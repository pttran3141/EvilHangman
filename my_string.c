#include "my_string.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct My_string
{
  int size;
  int capacity;
  char* data;

} My_string;


MY_STRING my_string_init_default()
{
  My_string* pMy_string = (My_string *)malloc(sizeof(My_string));
  if (pMy_string == NULL){
    free(pMy_string);
    return NULL;
  }
  pMy_string->size = 0;
  pMy_string->capacity = 7;
  pMy_string->data = (char*)malloc(sizeof(char)*pMy_string->capacity);
  if (pMy_string->data == NULL) {
    free(pMy_string);
    return NULL;
  }

  return (MY_STRING) pMy_string;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
  int length = 0;
  int k;

  while (c_string[length] != '\0'){
    length++;
  }
  
  My_string* pMy_string = (My_string*)malloc(sizeof(My_string));
  if (pMy_string==NULL)
  {
    free(pMy_string);
    return NULL;
  }
  pMy_string->size = length;
  pMy_string->capacity = (length + 1);

  pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
  if (pMy_string->data == NULL)
   {
     free(pMy_string->data);
     return NULL;
   }

  for (k=0; k <= pMy_string->size; k++)
   {
     pMy_string->data[k] = c_string[k];
   }

  return (MY_STRING) pMy_string;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;
  return pMy_string->capacity; 
}

int my_string_get_size(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;
  return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
  My_string* pLeft_string = (My_string*) hLeft_string;
  My_string* pRight_string = (My_string*) hRight_string;
  int i;

  if(hLeft_string == NULL || hRight_string == NULL)
  {
    if(hLeft_string == NULL)
    {
      return -1;
    }
    else if (hRight_string == NULL)
    {
      return 1;
    }
  }
  
  for  (i = 0; pLeft_string->data[i] == pRight_string->data[i]; i++)
  {
    if (pLeft_string->data[i] == '\0')
    {
      return 0;
    }
  }
       
  return (pLeft_string->data[i] - pRight_string->data[i]);
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
  char c;
  int i;
  char* tData = NULL;
  
  My_string* pMy_string = (My_string*) hMy_string;

  pMy_string->size = 0;

  c = fgetc(fp);
  
  while (c == EOF || c == ' ' || c == '\n')
  {
    if (c == EOF)
    {
      return FAILURE;
    }
    c = fgetc(fp);
  }
  
  while (c != EOF && c != ' ' && c  != '\n' && c != '\0')
  {
    
    if (pMy_string->size == (pMy_string->capacity - 1))
    {
      tData = (char*)malloc(sizeof(char) * (pMy_string->capacity * 2));
      if (tData == NULL)
      {
        return FAILURE;
      }
      for (i = 0; i<=pMy_string->size; i++)
      {
        pMy_string->data[i] = tData[i];
      }
	
      free(pMy_string->data);
      pMy_string->data = tData;
      pMy_string->capacity *= 2;
    }
      
    pMy_string->data[pMy_string->size] = c;
      
    pMy_string->size += 1;
      
    c = fgetc(fp);
  }
  
  if (c != EOF)
  {
    ungetc(c, fp);  
  }
  
  return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
  int i;
  My_string* pMy_string = (My_string*) hMy_string;

  if (pMy_string->size == 0)
  {
    return FAILURE;
  }
    
  for (i = 0; i < pMy_string->size; i++)
  {
    fputc(pMy_string->data[i], fp);
  }

  return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
  My_string* pMy_string = (My_string*) hMy_string;
  char* tData = NULL;
  int i;
  
  if (pMy_string->size == (pMy_string->capacity - 1))
  {
    tData = (char*)malloc(sizeof(char) * (pMy_string->capacity * 2));
    if (tData == NULL)
    {
      return FAILURE;
    }
    for (i = 0; i<=pMy_string->size; ++i)
    {
      tData[i] = pMy_string->data[i];
    }
    free(pMy_string->data);
    pMy_string->data = tData;
    pMy_string->capacity *= 2;    
  }

  pMy_string->data[pMy_string->size] = item;
  pMy_string->size += 1;
  return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;

  if(pMy_string->size == 0)
  {
    return FAILURE;
  }

  pMy_string->size -= 1;
  return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  char* letter;
  My_string* pMy_string = (My_string*) hMy_string;

  if(index >= 0 && index <= pMy_string->size)
  {
    letter = &pMy_string->data[index];
    return letter;
  }
  return NULL;
}

char* my_string_c_str(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;
  pMy_string->data[pMy_string->size] = '\0';
  return pMy_string->data;
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
  My_string* pResult = (My_string*) hResult;
  My_string* pAppend = (My_string*) hAppend;
  char* tData = NULL;
  int i,k;

  if ((pResult->size || pAppend->size) == 0)
  {
    return FAILURE;
  }
  if (pResult->capacity <= (pResult->size + pAppend->size))
  {
    tData = (char*)malloc(sizeof(char) * (pResult->size + pAppend->size) + 1);
    if (tData == NULL)
    {
      return FAILURE;
    }
    for (i=0; i <= pResult->size; i++)
    {
      tData[i] = pResult->data[i];
    }
    pResult->capacity += pAppend->size;
    free(pResult->data);
    pResult->data = tData;
  }

  for (k=0; k <= pAppend->size; k++)
  {
    pResult->data[pResult->size + k] = pAppend->data[k];
  }
  
  pResult->size += pAppend->size;
  
  return SUCCESS;
  
}

Boolean my_string_empty(MY_STRING hMy_string) {
  My_string* pMy_string = hMy_string;
  if (pMy_string->size == 0) {
    return TRUE;
  }
  return FALSE;
}

Status my_string_assignment(ITEM* pLeft, ITEM Right)
{
  My_string* pMy_string_left = *pLeft;
  My_string* pMy_string_right = Right;
  int i;
  char* tData = NULL;

  if ((pMy_string_right) == NULL)
  {
    return FAILURE;
  }

  if (*pLeft == NULL)
  {
    pMy_string_left = (My_string*)my_string_init_default();
  }
  
  
  if(pMy_string_left->capacity < pMy_string_right->capacity)
  {
    
    tData = (char*)malloc(sizeof(char) * pMy_string_right->capacity);
    if (tData == NULL)
    {
      free (tData);
      return FAILURE;
    }
    
    free(pMy_string_left->data);    
    pMy_string_left->data = tData;
  }

  pMy_string_left->size = pMy_string_right->size;
  pMy_string_left->capacity = pMy_string_right->capacity;

  for (i=0; i < pMy_string_right->size; i++)
  {
    pMy_string_left->data[i] = pMy_string_right->data[i];
  }

  *pLeft = pMy_string_left;
  return SUCCESS;
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
  My_string* pWord = (My_string*) word;
  My_string* pNew_key = (My_string*) new_key;
  int i;
  
  my_string_assignment(&new_key, current_word_family);

  for(i = 0; i<pWord->size; i++)
  {
    if(pWord->data[i] == guess)
    {
      pNew_key->data[i] = guess;
    }
  }
  
  return SUCCESS;
  
}

Boolean validate_guess(char guess, MY_STRING guessed_letters)
{
  My_string* hString = (My_string*) guessed_letters;
  int i;

  for (i = 0; i < hString->size; i++)
  {
    if (hString->data[i] == guess)
    {
      printf("You've already guessed that letter\n");
      return FALSE;
    }
  }
  return TRUE;
}

void my_string_destroy(ITEM* pItem)
{
  My_string* pMy_string = (My_string*) *pItem;
  free(pMy_string->data);
  free(pMy_string);
  *pItem = NULL;
  return;
}

