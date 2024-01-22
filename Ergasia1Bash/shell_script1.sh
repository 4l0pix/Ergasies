#!/bin/bash
clear # katharizume to termatiko gia mia kaliteri emfanisi
 # metaferomaste sto root directory gia na dimiourgisume tous fakelous
directory1="$1" # dexomste os parametro apo to termatiko to onoma tou fakelou pou theloume na dimiourgisoume 

if [ ! -d "$directory1" ]; then # an den iparxei o fakelos pou molis dextikame os parametro
    mkdir "$directory1" # ton dimiourgoume kai ton gemizoume me kapoia arxeia
    touch "$directory1/all_students.txt" "$directory1/all_grades.txt" "$directory1/all_classes.txt" "$directory1/gpa.txt" "$directory1/student_names.txt" "$directory1/contact_info.txt"
fi

cd "$directory1"
directory2="ALFILES" # dimiourgoume enan fakelo pou tha dextei ta arxeia pou ksekinane apo al-AL
directory3="OTHERFILES" # kai enan gia ta ypoloipa

if [ ! -d "$directory2" ]; then 	# 
    mkdir "$directory2"			#
fi					#
					# an den yparxoun oi fakeloi apo prin tote tous dimiourgoume
if [ ! -d "$directory3" ]; then		#
    mkdir "$directory3"			#
fi					#
echo "Δημιουργία φακέλων $directory2 & $directory3" # emfanizume kai ena minima dimiourgias ton fakelon
if [ ! -z "$(ls -A)" ]; then # elegxume an i lista epistrofis ton arxeioun tou directory1 einai adeia(an einai tote den borume na metaferoume ta arxeia giati poli apla den iparxoun)
	for file in *; do # elegxume ola ta arxeia ston parent folder
    		if [ -f "$file" ]; then # pragmatopoioume tin metafora mono an anaferomaste se arxeia (dioti o arxikos fakelos periexei mesa kai 2 fakelous tous opoious profanos den borume na metaferoume
    					#stous idious tous tous eaftous. Etsi apofevgoume ena subdirectory error pou tha proekipte se diaforetiki periptosi
    			filename=$(basename "$file") # sth metavliti 'filename' dinoume to onoma tou kathe arxeiou to opoio parinume me thn entoli basename
    			if [[ "$filename" =~ ^AL|^al ]]; then # an to onoma tou arxeiou ksekinaei apo al/AL tote metaferoume to arxeio ston antistoixo fakelo
        			mv "$file" "$directory2/"
    			else 				# se diaforetiki periptosi to metaferoume ston allo fakelo
        			mv "$file" "$directory3/"
    			fi
		fi
	done
	
	echo "Όλα τα αρχεία μεταφέρθηκαν!"
fi

