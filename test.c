#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
  uint8_t* buffer;
  uint16_t length;
  uint16_t capacity;
} ArrayList;

void append(ArrayList* list, uint8_t value){
  if(list->length >= list->capacity){
    printf("%s\n",list->buffer);
    void* ptr = realloc(list->buffer, list->capacity*2);
    printf("Realloced to %i\n", list->capacity*2);
    printf("%s\n",list->buffer);
    if (ptr != NULL){
      list->buffer = (uint8_t *) ptr;
      list->capacity *= 2;
    }else{
      exit(-1);
    }
  }
  list->buffer[list->length] = value;
  list->length++;
}

uint8_t get(ArrayList *list, uint16_t index){
  if(index <= list->length){
    return list->buffer[index];
  }
  return 0;
}

int main(){
  uint8_t* buf = malloc(2);
  ArrayList list = {buf, 0, 2};
  for(int i = 0; i < 2000; i++){
    append(&list, i);
  }
  }
