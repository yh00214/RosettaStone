/*************************************************************************
> File Name: AgentStructure.h
> Project Name: Hearthstone++
> Author: Young-Joong Kim
> Purpose: Agent Data Structure for Interact with Interface
> Created Time: 2017/10/24
> Copyright (c) 2017, Young-Joong Kim
*************************************************************************/
#ifndef HEARTHSTONEPP_AGENT_STRUCTURES_H
#define HEARTHSTONEPP_AGENT_STRUCTURES_H

#include <Models/Card.h>
#include <Models/Cards.h>
#include <Models/Entities/Hero.h>
#include <Models/Entities/HeroPower.h>
#include <Models/Entities/Weapon.h>
#include <Models/Player.h>

namespace Hearthstonepp
{
	using BYTE = unsigned char;

	struct User
	{
		User(Player* player, int deckID);

		int id;
		int totalMana;
		int existMana;
		int exhausted;

		std::string userID;
		Hero* hero;
		HeroPower* power;
		Weapon* weapon;

		std::vector<Card> cardDeck;

		std::vector<Card*> deck;
		std::vector<Card*> field;
		std::vector<Card*> hand;
		std::vector<Card*> usedSpell;
		std::vector<Card*> usedMinion;

		std::vector<Card*> attacked;
	};

	struct GameResult
	{
		std::string winner;
	};

	struct GameBrief
	{
		GameBrief(
			BYTE currentUser, BYTE oppositeUser, BYTE currentMana, BYTE oppositeMana, 
			BYTE numCurrentHand, BYTE numOppositeHand, BYTE numCurrentField, BYTE numOppositeField,
			Card* currentHero, Card* oppositeHero,
			Card** currentField, Card** currentHand, Card** oppositeField);
	
		BYTE id = static_cast<BYTE>(Action::BRIEF);

		BYTE currentUser;
		BYTE oppositeUser;
		BYTE currentMana;
		BYTE oppositeMana;

		BYTE numCurrentHand;
		BYTE numOppositeHand;
		BYTE numCurrentField;
		BYTE numOppositeField;

		Card* currentHero;
		Card* oppositeHero;

		Card** currentField;
		Card** currentHand;
		Card** oppositeField;
	};

	struct TargetingStructure
	{
		TargetingStructure(BYTE src, BYTE dst);

		BYTE src;
		BYTE dst;
	};

	struct DrawStructure
	{
		DrawStructure(BYTE drawID, BYTE userID, BYTE numDraw, Card** cards);

		BYTE id;
		BYTE userID;
		BYTE numDraw;
		Card** cards;
	};

	struct OverDrawStructure
	{
		OverDrawStructure(BYTE userID, BYTE numOver, Card** cards);

		BYTE id = static_cast<BYTE>(Action::OVER_DRAW);
		BYTE userID;
		BYTE numOver;
		Card** cards;
	};

	struct ExhaustDeckStructure
	{
		ExhaustDeckStructure(BYTE userID, BYTE numOver);

		BYTE id = static_cast<BYTE>(Action::EXHAUST_DECK);
		BYTE userID;
		BYTE numOver;
	};

	struct ModifyManaStructure
	{
		ModifyManaStructure(BYTE userID, BYTE mana);

		BYTE id = static_cast<BYTE>(Action::MANA_MODIFICATION);
		BYTE userID;
		BYTE mana;
	};

	struct ModifyHealthStructure
	{
		ModifyHealthStructure(BYTE userID, Card* card);

		BYTE id = static_cast<BYTE>(Action::HEALTH_MODIFICATION);
		BYTE userID;
		Card* card;
	};

	struct ExhaustMinionStructure
	{
		ExhaustMinionStructure(BYTE userID, Card* card);

		BYTE id = static_cast<BYTE>(Action::EXHAUST_MINION);
		BYTE userID;
		Card* card;
	};

	struct BeginFirstStructure
	{
		BeginFirstStructure(std::string& userFirst, std::string& userLast);

		BYTE id = static_cast<BYTE>(Step::BEGIN_FIRST);
		std::string& userFirst;
		std::string& userLast;
	};

	struct BeginShuffleStructure
	{
		BeginShuffleStructure(BYTE userID);

		BYTE id = static_cast<BYTE>(Step::BEGIN_SHUFFLE);
		BYTE userID;
	};

	struct BeginMulliganStructure
	{
		BeginMulliganStructure(BYTE userID);

		BYTE id = static_cast<BYTE>(Step::BEGIN_MULLIGAN);
		BYTE userID;
	};

	struct MainReadyStructure
	{
		MainReadyStructure(BYTE userID);

		BYTE id = static_cast<BYTE>(Step::MAIN_READY);
		BYTE userID;
	};

	struct MainMenuStructure
	{
		MainMenuStructure(BYTE userID);

		BYTE id = static_cast<BYTE>(Step::MAIN_START);
		BYTE userID;
	};

	struct MainUseCardStructure
	{
		MainUseCardStructure(BYTE userID, BYTE existMana, BYTE numFields, BYTE numHands, Card** hands);

		BYTE id = static_cast<BYTE>(Step::MAIN_ACTION);
		BYTE userID;
		BYTE existMana;
		BYTE numFields;
		BYTE numHands;
		Card** hands;
	};

	struct MainUseMinionStructure
	{
		MainUseMinionStructure(BYTE cardIndex, BYTE position);

		BYTE id = static_cast<BYTE>(CardType::MINION);
		BYTE cardIndex;
		BYTE position;
	};

	struct MainCombatStructure
	{
		MainCombatStructure(
			BYTE userID, BYTE numCurrentField, BYTE numOppositeField, 
			Card** currentField, Card** oppositeField);

		BYTE id = static_cast<BYTE>(Step::MAIN_COMBAT);
		BYTE userID;
		BYTE numCurrentField;
		BYTE numOppositeField;

		Card** currentField;
		Card** oppositeField;
	};

	struct MainEndStructure
	{
		MainEndStructure(BYTE userID);

		BYTE id = static_cast<BYTE>(Step::MAIN_END);
		BYTE userID;
	};

	struct FinalGameOverStructure
	{
		FinalGameOverStructure(BYTE winnerID);

		BYTE id = static_cast<BYTE>(Step::FINAL_GAMEOVER);
		BYTE winnerID;
	};
}

#endif