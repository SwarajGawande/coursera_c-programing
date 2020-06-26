#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"
#include "cards.h"
#include "future.h"

deck_t * hand_from_string(const char*str,future_cards_t *fc){
  deck_t *hand=malloc (sizeof(*hand));
  hand->cards=NULL;
  hand->n_cards=0;
  int i=0;
  // size_t len=strlen(str);
  while(str[i]!='\n'){
    if(str[i]==' '){
      i++;
      continue;
    }
    if(str[i]=='?'){
      int n=atoi(&str[i+1]);
      hand->cards=realloc(hand->cards,(hand->n_cards+1)*sizeof(*hand->cards));
      card_t * ptr=add_empty_card(hand);
      add_future_card(fc,n,ptr);
      hand->n_cards++;
      i=i+2+n/10;
      continue;
    }
    hand->cards=realloc(hand->cards,(hand->n_cards+1)*sizeof(*hand->cards));
    card_t * card=malloc(sizeof(*card));
    card_t c=card_from_letters(str[i],str[i+1]);
    card->value=c.value;
    card->suit=c.suit;
    (*hand).cards[hand->n_cards]=card;
    hand->n_cards++;
    i=i+2;
  }
  if(hand->n_cards<5){
    fprintf(stderr,"hand size too small\n");
    exit(EXIT_FAILURE);
  }
  return hand;
}

deck_t ** read_input(FILE * f,size_t * n_hands,future_cards_t *fc){
  char*line=NULL;
  size_t sz=0;
  ssize_t len;
  size_t  i=0;
  deck_t ** array=NULL;
  while((len=getline(&line,&sz,f))>=0){
    array=realloc(array,(i+1)*sizeof(*array));
    array[i]=hand_from_string(line,fc);
    i++;
    free(line);
    line=NULL;
  }
  free(line);
  *n_hands=i;
  /*if(*n_hands<5){
    fprintf(stderr,"hand size too small\n");
    exit(EXIT_FAILURE);
    }*/
  return array;
}
