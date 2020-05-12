#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert ((c.value<=14)&&(c.value>=2)&&(c.suit>=SPADES)&&(c.suit<=CLUBS));
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH:return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:return "FOUR_OF_A_KIND";
  case FULL_HOUSE :return "FULL_HOUSE";
  case FLUSH : return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  case NOTHING:return "NOTHING";
  default:return "";
      }
}

char value_letter(card_t c) {
  switch(c.value){
  case 2 : return'2';
  case 3 : return'3';
  case 4 : return'4';
  case 5 : return'5';
  case 6 : return'6';
  case 7: return'7';
  case 8: return'8';
  case 9: return'9';
  case 10:return'0';
  case 11:return'J';
  case 12: return'Q';
  case 13: return'K';
  case 14: return'A';
  }
  return 'x';
}


char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES:return's';
  case HEARTS:return'h';
  case DIAMONDS:return'd';
  case CLUBS:return'c';
  case NUM_SUITS:return '4';
  }
    return 'x';
  
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c),suit_letter(c));

}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){
  case'2':temp.value=2;break;
  case'3':temp.value=3;break;
  case'4':temp.value=4;break;
  case'5':temp.value=5;break;
  case'6':temp.value=6;break;
  case'7':temp.value=7;break;
  case'8':temp.value=8;break;
  case'9':temp.value=9;break;
  case'0':temp.value=10;break;
  case'J':temp.value=11;break;
  case'Q':temp.value=12;break;
  case'K':temp.value=13;break;
  case'A':temp.value=14;break;
  }
  switch(suit_let){
  case's':temp.suit=SPADES;break;
  case'h':temp.suit=HEARTS;break;
  case'd':temp.suit=DIAMONDS;break;
  case'c':temp.suit=CLUBS;break;
  }
    return temp;
}

card_t card_from_num(unsigned c) {
  assert(c>=0&&c<52);
  card_t temp;
  int c1=c/13;
  int c2=(c%13)+2;
  temp.value=c2;
    if (c1==0){
    temp.suit=SPADES;
    }
    else if (c1==1){
      temp.suit=HEARTS;
    }
    else if (c1==2){
      temp.suit=DIAMONDS;
    }
    else{
      temp.suit=CLUBS;
    }
  return temp;
}
