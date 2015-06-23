#ifndef __MAINAPPLICATIONSTATE_H__
#define __MAINAPPLICATIONSTATE_H__

#include <Headers/ToolClasses/Singleton.h>
#include <Headers/ApplicationStates/AbstractTimeableApplicationState.h>
#include <Headers/ToolClasses/FinalClass.h>

namespace pan {
	class MainApplicationState : public Singleton <MainApplicationState>, public AbstractTimeableApplicationState, virtual FinalClass {
		SET_SINGLETON(MainApplicationState)

	protected:
		MainApplicationState();
		virtual ~MainApplicationState() override;
	public:
		void initializeEgine();
		virtual Bool init() override;
		virtual void draw() override;
		virtual Bool update() override;
		virtual void shutdown() override;
		virtual void render() override;
		std::string getId() const;
	};
}

#endif