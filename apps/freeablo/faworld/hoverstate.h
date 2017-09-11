#pragma once

#include "world.h"

namespace FAWorld
{
    enum class HoverType
     {
        actor,
        none,
    };

    class HoverState // TODO: change it to boost::variant
    {
        HoverType mType = HoverType::none;
        int32_t mActorId = 0;

      public:
        HoverState()
        {
        }
        bool applyIfNeeded(const HoverState& newState);
        bool operator==(const HoverState& other) const;
        // for now this function if state was applied and if it was caller should ask guimanager to update status bar
        // later on logic probably will be different.
        bool setActorHovered(int32_t actorIdArg);
        bool setNothingHovered();
        bool isActorHovered(int32_t actorId) const;

      private:
        HoverState(HoverType typeArg) : mType(typeArg)
        {
        }
    };
}

