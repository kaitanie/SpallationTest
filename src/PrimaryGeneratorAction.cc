/* 
 * File:   primarygeneratoraction.cc
 * Author: user
 * 
 * Created on May 6, 2009, 8:53 AM
 */

#include "PrimaryGeneratorAction.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction() {
  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  particleGun->SetParticleDefinition(particleTable->FindParticle(particleName="proton"));
  particleGun->SetParticleEnergy(1.0*GeV);
  particleGun->SetParticlePosition(G4ThreeVector(-2.0*m, 0.0, 0.0));
}

PrimaryGeneratorAction::PrimaryGeneratorAction(const PrimaryGeneratorAction& orig) {
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)
{
  //G4int i = anEvent->GetEventID() % 3;
  G4ThreeVector v(1.0,0.0,0.0);

  particleGun->SetParticleMomentumDirection(v);
  particleGun->GeneratePrimaryVertex(anEvent);
   
}