#include <stdlib.h>
#include <stdio.h>
#include "cards.h"
#include "deck.h"
#include "future.h"

void add_future_card(future_cards_t *fc,size_t index,card_t * ptr){
  if(index>=fc->n_decks){
  fc->decks=realloc(fc->decks,(index+1)*sizeof(*fc->decks));
  while(fc->n_decks<=index){
    fc->decks[fc->n_decks-1].cards=NULL;
    fc->decks[fc->n_decks-1].n_cards=0;
    fc->n_decks++;
  }
  (*fc).decks[index].n_cards=1;
  (*fc).decks[index].cards=realloc(fc->decks[index].cards,(*fc).decks[index].n_cards*sizeof(*fc->decks[index].cards));
  (*fc).decks[index].cards[(*fc).decks[index].n_cards-1]=ptr;
  }
  else{
  (*fc).decks[index].n_cards++;
  (*fc).decks[index].cards=realloc(fc->decks[index].cards,(*fc).decks[index].n_cards*sizeof(*fc->decks[index].cards));
  (*fc).decks[index].cards[(*fc).decks[index].n_cards-1]=ptr;
  }
}

void future_cards_from_deck(deck_t * deck,future_cards_t *fc){
  if(deck->n_cards<fc->n_decks){
    fprintf(stderr,"too many unknown/future cards\n");
    exit(EXIT_FAILURE);
  }
  for(int i=0;i<fc->n_decks;i++){
    for(int j=0;j<(*fc).decks[i].n_cards;j++){
      (*(*fc).decks[i].cards[j]).value=(*deck->cards[i]).value;
      (*(*fc).decks[i].cards[j]).value=(*deck->cards[i]).value;
    }
  }
}
