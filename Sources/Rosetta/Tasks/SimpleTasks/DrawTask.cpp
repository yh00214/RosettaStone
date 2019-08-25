// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#include <Rosetta/Actions/Draw.hpp>
#include <Rosetta/Games/Game.hpp>
#include <Rosetta/Tasks/SimpleTasks/DrawTask.hpp>

namespace RosettaStone::SimpleTasks
{
DrawTask::DrawTask(int amount, bool toStack)
    : m_amount(amount), m_toStack(toStack)
{
    // Do nothing
}

DrawTask::DrawTask(bool toStack)
    : m_toStack(toStack), m_stackNum(true)
{
    // Do nothing
}

TaskID DrawTask::GetTaskID() const
{
    return TaskID::DRAW;
}

TaskStatus DrawTask::Impl(Player& player)
{
    std::vector<Entity*> cards;

    const int amount = m_stackNum ? player.GetGame()->taskStack.num : m_amount;

    for (int i = 0; i < amount; ++i)
    {
        Entity* card = Generic::Draw(player, nullptr);
        cards.emplace_back(card);
    }

    if (cards.empty() || cards.at(0) == nullptr)
    {
        return TaskStatus::COMPLETE;
    }

    if (m_toStack)
    {
        player.GetGame()->taskStack.entities.clear();

        for (auto& card : cards)
        {
            player.GetGame()->taskStack.entities.emplace_back(card);
        }
    }

    return TaskStatus::COMPLETE;
}

ITask* DrawTask::CloneImpl()
{
    return new DrawTask(m_amount, m_toStack);
}
}  // namespace RosettaStone::SimpleTasks
