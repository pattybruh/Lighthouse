#include <Lighthouse.h>

class GameA : public Lighthouse::Application{
public:
	GameA() {

	}
	
	~GameA() {

	}
};

Lighthouse::Application* Lighthouse::CreateApplication() {
	return new GameA();
}