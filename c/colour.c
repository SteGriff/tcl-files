#include <stdio.h>

int str_length(char* astring){
  int length=0;
  for(length=0; astring[length]!='\0'; ++length){
  }
  return length+1;
}

void to_lower(char* *astring){

  printf("Given %s\n",*astring);
  
  int length= str_length(*astring);
  int i=0;
  for(i=0;i<length;++i){
    char thischar = (*astring)[i];
    int charnum = thischar;
    printf("p%i [%c]=%i ... ",i,thischar,charnum);
    
    if (charnum>64 && charnum<91){
      printf("is magiscule: \n");
      
      charnum += 32;
      thischar = charnum;
      printf("New char is [%c]\n",thischar);
      *astring+1 = thischar;
      printf("made [%c]",(*astring)[i]);
      
    }
    else
      printf("already miniscule.\n");
      
  }
}

int str_any_case_same(char* string1, char* string2){
  int l1 = str_length(string1);
  int l2 = str_length(string2);
  printf("%i and %i equal? Boolean %i\n",l1,l2,l1==l2);
  if (l1==l2){
    return 0;
  }
  else
    return 0;
  
}

int index_of(char* needle, char* haystack[], int haysize){
  int i=0;
  for(i=0; i<haysize; ++i){
    if(haystack[i] == needle){
      return i;
    }
  }
  return -1;
}

int colour_number_of(char* colourname){
  char* colours[] = {"red","green","yellow","blue","magenta","cyan","white"};
  return 0;
}

int main(int argc, char* argv[]){
  char* test1="HomeLy";
  
  to_lower(&test1); 
  /* 
  switch (argc){
    case 2:
      int colour_number;
      colour_number=colour_number_of(argv[1]);
      printf("OK, so you entered [%s], which is %i.",argv[1],colour_number);
      break;
    case 3:
      break; 
    default:
      printf("Usage: colour colourname [0/1]");

  }*/
  return 0;
}

