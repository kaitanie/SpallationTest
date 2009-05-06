/* 
 * File:   primarygeneratoraction.hh
 * Author: user
 *
 * Created on May 6, 2009, 8:53 AM
 */

#ifndef _PRIMARYGENERATORACTION_HH
#define	_PRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    PrimaryGeneratorAction();
    PrimaryGeneratorAction(const PrimaryGeneratorAction& orig);
    ~PrimaryGeneratorAction();
    
public:
    void GeneratePrimaries(G4Event* anEvent);

private:
    G4ParticleGun *theGun;
};

#endif	/* _PRIMARYGENERATORACTION_HH */

