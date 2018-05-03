#include "../../inc/DSEnemy.h"
#include "Components/SphereComponent.h"
#include <string.h>

int CurrScore = 0;
int EnemyCount = 0;
// Sets default values
ADSEnemy::ADSEnemy(const class FObjectInitializer &Initializer)
	: Super(Initializer)
{
	// Set this pawn to call Tick() every frame.  
	// You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADSEnemy::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADSEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADSEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADSEnemy::SendHighScore(int score, FString name) {
	const FString string = FString::Printf(TEXT("cmd /c C:\\Users\\Frostbyte\\Documents\\GitHub\\Team4Game\\Source\\Team4Game\\src\\drew\\hssclient.exe 52.160.46.238 1 %s %d & pause"), *name, score);
	auto ansi_string = StringCast<ANSICHAR>(*string);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, string);
	const TCHAR* Ineedhelp = *string;
	//FPlatformProcess::CreateProc(Ineedhelp,nullptr,true,false,false,nullptr,0,nullptr,nullptr);
}

int ADSEnemy::ChangeEnemyAmount(int amountToChange) { //Keep EnemyCount known only to the function itself
	EnemyCount += amountToChange;
	return EnemyCount;
}

int ADSEnemy::AddToScore(int scoreToAdd) {
	//static int CurrScore = 0; //Keep CurrScore known only to the function itself
	CurrScore += 50;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Score is: %d"), CurrScore));
	return CurrScore;
}

void ADSEnemy::ResetScore() {
    CurrScore = 0;
}
