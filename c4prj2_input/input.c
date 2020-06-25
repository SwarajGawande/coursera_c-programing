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
      n_cards++;
      i=i+2+n/10;
    }
    hand->cards=realloc(hand->cards,(hand->n_cards+1)*sizeof(*hand->cards));
    card_t * card=malloc(sizeof(*card));
    card_t c=card_from_letters(str[i],str[i+1]);
    card->value=c.value;
    card->suit=c.suit;
    (*hand).cards[n_cards]=card;
    n_cards++;
    i=i+2;
  }
  return hand;
}

deck_t ** read_input(FILE * f,size_t * n_hands,future_cards_t *fc){
  char*line=NULL;
  size_t sz=0;
  ssize_t len;
  *n_hands=0;
  deck_t ** array=NULL;
  while((len=getline(&line,&sz,f))>=0){
    array=realloc(array,(*n_hands+1)*sizeof(*array));
    array[*n_hands]=hand_from_string(line,fc);
    *n_hands++;
  }
  if(*n_hands<5){
    fprintf(stderr,"hand size too small\n");
    exit(EXIT_FAILURE);
  }
  return array;
}
