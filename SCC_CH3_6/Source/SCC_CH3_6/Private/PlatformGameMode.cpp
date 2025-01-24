#include "PlatformGameMode.h"
#include "PlayerCharacter.h"
#include "CharacterPlayerController.h"

APlatformGameMode::APlatformGameMode()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
	PlayerControllerClass = ACharacterPlayerController::StaticClass();
}