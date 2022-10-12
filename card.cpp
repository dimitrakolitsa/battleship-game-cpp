#include "card.h"


Card:: Card(int id, string text)
{
    this->id = id;
    this->text = text;
};
int Card:: getId()
{
    return id;
};
string Card:: getText()
{
    return text;
};
PointCard::PointCard(int id, string text, int points) :Card(id,text)
{
    this->points = points;
};

void PointCard::cardAction(Player* player, Player* opponent)
{
     //if points>0, player gets points and opponent loses points
     //if points<0, negative points are added to players's points [+(-)] so he loses points
     //and negative points are removed from the opponent's points [-(-)] so the opponent receives points
     player->addPoints(points);
     opponent->removePoints(points);

};


MoveCard:: MoveCard(int id, string text, MoveType type):Card(id, text) //calls constructor of base class
{
    this->type=type;
};

void MoveCard::cardAction(Player* player, Player* opponent)
{
    switch(type)
    {
    case DoNothing: //nothing happens
        break;
    case PlayTwice:
        opponent->missNextTurn(); //player plays twice because the opponent misses a turn
        break;
    case MissTurn:
        player->missNextTurn(); //player misses turn so opponent plays twice
        break;
    };

};
