#! /bin/sh
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' #no colour


if [[ $1 = "-d" ]];
then rm error_file_3nums.txt error_file_4nums.txt error_file_5nums.txt success_3nums.txt success_4nums.txt success_5nums.txt
else
  declare -a StringArray=("1 2 3 4 5" "1 2 3 5 4" "1 2 4 3 5" "1 2 4 5 3" "1 2 5 3 4" "1 2 5 4 3" "1 3 2 4 5" "1 3 2 5 4" "1 3 4 2 5" "1 3 4 5 2" "1 3 5 2 4" "1 3 5 4 2" "1 4 2 3 5" "1 4 2 5 3" "1 4 3 2 5" "1 4 3 5 2" "1 4 5 2 3" "1 4 5 3 2" "1 5 2 3 4" "1 5 2 4 3" "1 5 3 2 4" "1 5 3 4 2" "1 5 4 2 3" "1 5 4 3 2" "2 1 3 4 5" "2 1 3 5 4" "2 1 4 3 5" "2 1 4 5 3" "2 1 5 3 4" "2 1 5 4 3" "2 3 1 4 5" "2 3 1 5 4" "2 3 4 1 5" "2 3 4 5 1" "2 3 5 1 4" "2 3 5 4 1" "2 4 1 3 5" "2 4 1 5 3" "2 4 3 1 5" "2 4 3 5 1" "2 4 5 1 3" "2 4 5 3 1" "2 5 1 3 4" "2 5 1 4 3" "2 5 3 1 4" "2 5 3 4 1" "2 5 4 1 3" "2 5 4 3 1" "3 1 2 4 5" "3 1 2 5 4" "3 1 4 2 5" "3 1 4 5 2" "3 1 5 2 4" "3 1 5 4 2" "3 2 1 4 5" "3 2 1 5 4" "3 2 4 1 5" "3 2 4 5 1" "3 2 5 1 4" "3 2 5 4 1" "3 4 1 2 5" "3 4 1 5 2" "3 4 2 1 5" "3 4 2 5 1" "3 4 5 1 2" "3 4 5 2 1" "3 5 1 2 4" "3 5 1 4 2" "3 5 2 1 4" "3 5 2 4 1" "3 5 4 1 2" "3 5 4 2 1" "4 1 2 3 5" "4 1 2 5 3" "4 1 3 2 5" "4 1 3 5 2" "4 1 5 2 3" "4 1 5 3 2" "4 2 1 3 5" "4 2 1 5 3" "4 2 3 1 5" "4 2 3 5 1" "4 2 5 1 3" "4 2 5 3 1" "4 3 1 2 5" "4 3 1 5 2" "4 3 2 1 5" "4 3 2 5 1" "4 3 5 1 2" "4 3 5 2 1" "4 5 1 2 3" "4 5 1 3 2" "4 5 2 1 3" "4 5 2 3 1" "4 5 3 1 2" "4 5 3 2 1" "5 1 2 3 4" "5 1 2 4 3" "5 1 3 2 4" "5 1 3 4 2" "5 1 4 2 3" "5 1 4 3 2" "5 2 1 3 4" "5 2 1 4 3" "5 2 3 1 4" "5 2 3 4 1" "5 2 4 1 3" "5 2 4 3 1" "5 3 1 2 4" "5 3 1 4 2" "5 3 2 1 4" "5 3 2 4 1" "5 3 4 1 2" "5 3 4 2 1" "5 4 1 2 3" "5 4 1 3 2" "5 4 2 1 3" "5 4 2 3 1" "5 4 3 1 2" "5 4 3 2 1")
  echo "Below you can find the inputs which take more than 12 instrucitons to sort:" > error_file_5nums.txt
  echo "All successful tests:" > success_5nums.txt

  for val in "${StringArray[@]}"
  do 
    RESULT=$(./push_swap $val | wc -l)
    if [ $RESULT -gt 12 ]
      then
        echo "Error with test input: $val. Instructions: $RESULT" >> error_file_5nums.txt
      else
        echo "Test input: $val. Instructions: $RESULT" >> success_5nums.txt
    fi
  done

  declare -a StringArray=("-1 0 1 2" "-1 0 2 1" "-1 1 0 2" "-1 1 2 0" "-1 2 0 1" "-1 2 1 0" "0 -1 1 2" "0 -1 2 1" "0 1 -1 2" "0 1 2 -1" "0 2 -1 1" "0 2 1 -1" "1 -1 0 2" "1 -1 2 0" "1 0 -1 2" "1 0 2 -1" "1 2 -1 0" "1 2 0 -1" "2 -1 0 1" "2 -1 1 0" "2 0 -1 1" "2 0 1 -1" "2 1 -1 0" "2 1 0 -1")
  echo "Below you can find the inputs which take more than 10 instrucitons to sort:" > error_file_4nums.txt
  echo "All successful tests:" > success_3nums.txt

  for val in "${StringArray[@]}"
  do 
    RESULT=$(./push_swap $val | wc -l)
    if [ $RESULT -gt 10 ]
      then
        echo "Error with test input: $val. Instructions: $RESULT" >> error_file_4nums.txt
      else
        echo "Test input: $val. Instructions: $RESULT" >> success_4nums.txt
    fi
  done

  declare -a StringArray=("1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1")
  echo "Below you can find the inputs which take more than 3 instrucitons to sort:" > error_file_3nums.txt
  echo "All successful tests:" > success_3nums.txt

  for val in "${StringArray[@]}"
  do 
    RESULT=$(./push_swap $val | wc -l)
    if [ $RESULT -gt 3 ]
      then
        echo "Error with test input: $val. Instructions: $RESULT" >> error_file_3nums.txt
      else
        echo "Test input: $val. Instructions: $RESULT" >> success_3nums.txt
    fi
  done

  SUCCESS_3=$(cat error_file_3nums.txt | wc -l)
  SUCCESS_4=$(cat error_file_4nums.txt | wc -l)
  SUCCESS_5=$(cat error_file_5nums.txt | wc -l)
  if [ $SUCCESS_3 -lt 2 ]
    then echo -e "${GREEN}SUCCESS:${NC} 3-number permutations all take less than 4 operations."
    else echo -e "${RED}ERROR. Refer to error_file_3nums.txt"
  fi
  if [ $SUCCESS_4 -lt 2 ]
    then echo -e "${GREEN}SUCCESS:${NC} 4-number permutations all take less than 11 operations."
    else echo -e "${RED}ERROR. Refer to error_file_4nums.txt"
  fi
  if [ $SUCCESS_3 -lt 2 ]
    then echo -e "${GREEN}SUCCESS:${NC} 5-number permutations all take less than 13 operations."
    else echo -e "${RED}ERROR. Refer to error_file_5nums.txt"
  fi

fi


