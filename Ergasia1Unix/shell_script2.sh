#!/bin/bash
eisagwgi_stoixeiou_foititi(){ # Dimiourgw mia sinartisi gia tin eisagwgi ton stoixeiwn tou foititi
	# H sinartisi afth tha xrisimopoihthei toso sthn 1h epilogh oso kai sthn 2h
	local file_name=$1 # Metaferoume os parametro to onoma tou arxeiou sto opoio epithimume na kanoume thn metafora
	read -p "Εισάγετε κωδικό--->" kwdikos		#
	read -p "Εισάγετε επώνυμο--->" epitheto		# Zitame input gia ta 3 prwta stoixeia
	read -p "Εισάγετε όνομα--->" onoma		#
	while true; do						#
		read -p "Εισάγετε αριθμό ταυτότητας--->" am	#
		if [[ "$am" =~ ^[0-9]+$ ]]; then		# Stin sinexeia ekteloume enan elegxo timwn etsi oste o AM na einai arithmos
			break					#
		else						#
			echo "Ο αριθμός ταυτότητας πρέπει να περιέχει μόνο χαρακήτηρες(0-9)!"
		fi
	done
	# Sinexizume me thn eisagwgi ton stoixeion
	read -p "Εισάγετε βαθμό--->" vathmos		
	read -p "Εισάγετε τμήμα--->" tmima		
	echo "$kwdikos $onoma $epitheto $am $vathmos $tmima"  >> "$file_name"	# Pragmatopoioume eggrafi ton stoixeion sto antistoixo arxeio
}

func1(){
	# Se afth th sinartisi tha pragmatopoihsoume epanalliptiki klhsh ths sinartisis 'eisagwgi_stoixeiou_foititi'
	# Diladi pragmatopoioume eggrafi foititon eos otou o xristis na apofasisei oti den epithimei na sinexisei
	while true; do
		local file_name=$1
		clear
		echo "Δημιουργία ενός αρχείου με στοιχεία φοιτητών ενός πανεπιστημίου"
		eisagwgi_stoixeiou_foititi "$file_name"
		echo "Θα θελατε να εισάγετε και άλλο φοιτητή; y/n--->"
		read choice
		if [ "$choice" == "n" ] || [ "$choice" == "N" ]; then
			clear
			break
		fi
	done
}

func2(){
	clear
	echo "2. Προσθήκη νέου φοιτητή στο υπάρχον αρχείο"
	echo "Τα πεδία είναι ως εξής" 	# Ektiponoum ena enimerotiko minima sxetika me to format/layout ton stoixeion tis kathe eggrafis
	echo "Κωδικός   Όνομα   Επίθετο   ΑριθμόςΤαυτότητας   Βαθμός   Μάθημα"
	read -p "Παρακαλώ εισάγετε το όνομα του αρχείου προς ανάγνωση--->" file_name	#
	while true; do									#
		if [ -e "$file_name" ]; then						# Pragmatopoioume fortosi tou arxeiou
			echo "Επιτυχής φόρτωση αρχείου!"				# an afto iparxei
			eisagwgi_stoixeiou_foititi "$file_name"				#
		else
			echo "Το αρχείο δεν υπάρχει! Δημιουργία αρχείου..."		# Se diaforetiki periptosi to dimiourgoume
			sleep 2s	# Pragmatopoioume kapoia tricks me ton xrono gia na einai to programma pio efparusiasto
			clear
			touch "$file_name" # Dimiourgoume to arxeio
			chmod 777 "$file_name"  # Dinoume prosvasi se periptosi pou o user apo default den exei gia na grapsei sto arxeio(prosferume parapanw dikaiomata enw einai perita, eimaste gennaiodoroi)
			echo "Το αρχείο δημιουργήθηκε με επιτυχία!"
			eisagwgi_stoixeiou_foititi "$file_name"	# Kaloume tin sinartisi kai tis parexoume tin analogi parametro
			echo "Η εγγραφή στο νέο αρχείο πραγματοποιήθηκε με επιτυχία!"
			break
		fi
	done
}

func3(){
	clear
	echo "3. Αναζήτηση φοιτητή με βάση τον αριθμό μητρώου του"
	read -p "Παρακαλώ εισάγετε το όνομα του αρχείου προς ανάγνωση--->" file		
	while true; do		# Pragmatopoioume kai se afto to simeio enan elegxo iparksis tou arxeiou							
		if [ ! -e "$file" ]; then
			read -p "Το αρχείο που πλκτρολογίσατε δεν υπάρχει παρακαλώ προσπαθήστε ξανά!" file
		else 
			break
		fi
	done
	# Se afti tin sinartisi omos an to arxei oden vrethei, den to dimiourgoume alla epimenoume eos otou o xristis eisagei kapoio iparkto
	echo "Επιτυχής φόρτωση αρχείου!"
	while true; do
		read -p "Ειάγετε αριθμό τραυτότητας προς αναζήτηση (0-9)μήκος 6 χαρακτήρες!--->" am
		if [[ "$am" =~ ^[0-9]{6}$ ]]; then	# Pragmatopoioume enan elegxo tis timis (0-9 kai mikous 6)
			# anazitisi foititi
			if awk -v am="$am" '$4 == am' "$file" | grep -q "$am"; then # an vrethei ektiponoume oli ti seira me to grep 
				clear
				echo "$(grep -w "$am" "$file")"
				sleep 2
				break
			else
				echo "Ο αριθμός ταυτότητας που δώσατε δεν υπάρχει:/" # diaforetika emfanizume minima lathus
				sleep 2
				clear 
				break
			fi
		else 	# an o arithmos taftotitas den plirei tis proipotheseis
			# emfanizume minima lathus	
			echo "Ο αριθμός ταυτότητας πρέπει να έχει μήκος 6 χαρακτήρες και να περιέχει μόνο χαρακήτηρες(0-9)!"
		fi
	done
}

func4(){
	local file_name=$1 # Metaferume to onoma tou arxeiou sth sinartisi
	declare -a array # Dilwnoume enan pinaka ston oipoio tha apothikefsume oli tin stili ton mathimaton
	declare -a sorted_array # Dilwnoume allon enan pinaka sto opoio omos tha kataxwrisume ta diaforetika mathimata pou emfanizontai mesa sto arxeio(xwris diplotipa)
	clear # Katharizume to termatiko gia logous aisthitikis opos se polla alla simeia tou kwdika
	echo "4. Προβολή στατιστικών στοιχείων"
	
	while IFS= read -r grammi; do # Apothikevume tin kathe grammi tou keimenou stin metavliti 'grammi' 
	# H entoli IFS= xrisimopoieitai gia na ginei i epanalipsi mexri na teleiwsoun ta contents tou arxeiou
    		element=$(echo "$grammi" | awk '{print $6}')  # Apo tin grammi pou molis diavasame kratame to periexomeno tis 6hs stilis(stin opoia vrisketai to mathima
    		array+=("$element") # Prosthetume to mathima ston pinaka
	done < "$file_name"  # Se afto to simeio prosdiorizume kai to arxeio sto opoio tha lavei meros i epanalipsi
	
	sorted_array=($(printf "%s\n" "${array[@]}" | sort -u)) # Ekteloume taksinomisi kai me tin epilogi -u eksalifoume ta diplotipa
	
	# Etsi exoume ton original pinaka 'array' me ta periexomena tou arxeiou kai ton pinaka 'sorted_array' gia sigrisi
	# Tha psaksume loipon gia kathe stoixeio tou 'sorted_array' poses fores emfanizetai ston 'array' ara tosoi tha einai kai oi mathites sto arxeio
	
	for mathima in  "${sorted_array[@]}"; do # Apli prospelasi ston pinaka ton mathimaton (xwris ta diplotipa)
		count=0 # Arxikopoihsh enos metriti gia tis emfaniseis tou kathe mathimatos
		for element in "${array[@]}"; do # Emfolevmena ekteloume mia epanalipsi h opoia tha prospelasei ton original pinaka 
			if [ "$element" == "$mathima" ]; then # Ean emfanistei kapoia taftisi metaksi ton periexomenwn twn dio pinakon
				((count++)) # Prosafksanume to plithos emfanisis
			fi
		done
		echo "$mathima $count" # Emfanizume kai to plithos ton mathiton sto kathe mathima
	done
}

func_exit(){
	clear
	echo "Έξοδος!"
	sleep 1s # Kanoume mia pafsi tou enos defteroleptou
	clear # Svinume kai to minima eksodou kai etsi to termatiko einai sa na min anoikse pote to programma(pio omorfo)
	exit 0 # Termatizume to programma
}

main(){	
	file_name="stoixeia_foititon.txt" # Orizoume to onoma tou arxeiou pou tha periexei ta stoixeia ton foititon
	if [ ! -e "$file_name" ]; then
    		touch "$file_name"
    		chmod 777 "$file_name"  
    	fi	
	clear # Katharizume to terminal apo tixon proigumenes diergasies
	while true; do # dimiourgoume ena vroxo o opoios tha termatizetai otan dothei os epilogi to 5
		echo "1. Δημιουργία ενός αρχείου με στοιχεία φοιτητών ενός πανεπιστημίου"
		echo "2. Προσθήκη νέου φοιτητή στο υπάρχον αρχείο"
		echo "3. Αναζήτηση φοιτητή με βάση τον αριθμό μητρώου του"
		echo "4. Προβολή στατιστικών στοιχείων"
		echo "5. Έξοδος " 
		echo "Επιλογή--->"
		read answer # dexomaste input apo to xristi
		if [ "$answer" -eq 5 ]; then    # an o xristis epileksei 5.exodos
			func_exit		# kaloume thn synartisi func_exit
		elif [ "$answer" -eq 1 ]; then
			func1 "$file_name" 	# kaloume thn synartisi func1
			echo "Επιτυχής εγγραφή!"
		elif [ "$answer" -eq 2 ]; then
			func2 "$file_name"	# kaloume thn synartisi func2
		elif [ "$answer" -eq 3 ]; then
			func3			# kaloume thn synartisi func3
		elif [ "$answer" -eq 4 ]; then
			func4 "$file_name"	# kaloume thn synartisi func4
		else
			echo "Εισάγετε μία από τις παραπάνω επιλογές!"	# emfanizoume minima lathous
		fi
	done
}
main # Kaloume tin main function
