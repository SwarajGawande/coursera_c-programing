#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_card(card_t c);

void print_hand(deck_t * hand){
  for(int i=0;i<hand->n_cards;i++){
    print_card((*(*hand).cards[i]));
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  for (int i=0;i<d->n_cards;i++){
    if ((*(*d).cards[i]).value==c.value&&(*(*d).cards[i]).suit==c.suit){
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  for (int i=0;i<2*(d->n_cards);i++){
    int n=random()%(d->n_cards);
    card_t temp=**(*d).cards;
    **(*d).cards=*((*d).cards[n]);
    *((*d).cards[n])=temp;
  }
}

void assert_full_deck(deck_t * d) {
  for (int i=0;i<d->n_cards;i++){
    for (int j=i+1;j<d->n_cards;j++){
      if ((*(*d).cards[i]).value==(*(*d).cards[j]).value&&(*(*d).cards[i]).suit==(*(*d).cards[j]).suit){
  	printf("invalid deck");
  	return;
      }
    }
  }
}

