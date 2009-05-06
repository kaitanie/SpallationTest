//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: DetectorConstruction.cc,v 1.9 2006/06/29 17:47:19 gunter Exp $
// GEANT4 tag $Name: geant4-09-02-ref-00 $
//

#include "DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "globals.hh"

DetectorConstruction::DetectorConstruction()
 :  experimentalHall_log(0), tracker_log(0),
    calorimeterBlock_log(0), calorimeterLayer_log(0),
    experimentalHall_phys(0), calorimeterLayer_phys(0),
    calorimeterBlock_phys(0), tracker_phys(0)
{;}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{

  //------------------------------------------------------ materials

  G4double a;  // atomic mass
  G4double z;  // atomic number
  G4double density;

  G4Material* Vacuum =
          new G4Material("Galactic", z=1.0, a=1.01*g/mole, density=universe_mean_density,
          kStateGas, 2.73*kelvin, 3.0e-18*pascal);
  G4Material* Ar =
  new G4Material("ArgonGas", z= 18., a= 39.95*g/mole, density= 1.782*mg/cm3);

  G4Material* Al =
  new G4Material("Aluminum", z= 13., a= 26.98*g/mole, density= 2.7*g/cm3);

  G4Material* Pb =
  new G4Material("Lead", z= 82., a= 207.19*g/mole, density= 11.35*g/cm3);

  //------------------------------------------------------ volumes

  //------------------------------ experimental hall (world volume)
  //------------------------------ beam line along x axis

  G4double expHall_x = 3.0*m;
  G4double expHall_y = 1.0*m;
  G4double expHall_z = 1.0*m;
  G4Box* experimentalHall_box
    = new G4Box("expHall_box",expHall_x,expHall_y,expHall_z);
  experimentalHall_log = new G4LogicalVolume(experimentalHall_box,
                                             Vacuum,"expHall_log",0,0,0);
  experimentalHall_phys = new G4PVPlacement(0,G4ThreeVector(),
                                      experimentalHall_log,"expHall",0,false,0);

  G4double block_x = 1.0*mm;
  G4double block_y = 50.0*cm;
  G4double block_z = 50.0*cm;
  G4Box* calorimeterBlock_box = new G4Box("target_box",block_x,
                                          block_y,block_z);
  calorimeterBlock_log = new G4LogicalVolume(calorimeterBlock_box,
                                             Pb,"target_log",0,0,0);
  G4double blockPos_x = 1.0*m;
  G4double blockPos_y = 0.0*m;
  G4double blockPos_z = 0.0*m;
  calorimeterBlock_phys = new G4PVPlacement(0,
             G4ThreeVector(blockPos_x,blockPos_y,blockPos_z),
             calorimeterBlock_log,"target",experimentalHall_log,false,0);

  return experimentalHall_phys;
}


