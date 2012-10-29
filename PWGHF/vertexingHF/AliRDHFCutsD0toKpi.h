#ifndef ALIRDHFCUTSD0TOKPI_H
#define ALIRDHFCUTSD0TOKPI_H
/* Copyright(c) 1998-2010, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

/* $Id$ */ 

//***********************************************************
// Class AliRDHFCutsD0toKpi
// class for cuts on AOD reconstructed D0->Kpi
// Author: A.Dainese, andrea.dainese@pd.infn.it
//***********************************************************

#include "AliRDHFCuts.h"

class AliAODEvent;
class AliAODRecoDecayHF;
class AliAODRecoDecayHF2Prong;

class AliRDHFCutsD0toKpi : public AliRDHFCuts 
{
 public:

  AliRDHFCutsD0toKpi(const char* name="CutsD0toKpi");
  
  virtual ~AliRDHFCutsD0toKpi(){}

  AliRDHFCutsD0toKpi(const AliRDHFCutsD0toKpi& source);
  AliRDHFCutsD0toKpi& operator=(const AliRDHFCutsD0toKpi& source); 

  using AliRDHFCuts::GetCutVarsForOpt;
  virtual void GetCutVarsForOpt(AliAODRecoDecayHF *d,Float_t *vars,Int_t nvars,Int_t *pdgdaughters){
    return GetCutVarsForOpt(d,vars,nvars,pdgdaughters,0x0);
  }
  virtual void GetCutVarsForOpt(AliAODRecoDecayHF *d,Float_t *vars,Int_t nvars,Int_t *pdgdaughters,AliAODEvent *aod);

  using AliRDHFCuts::IsSelected;
  virtual Int_t IsSelected(TObject* obj,Int_t selectionLevel) 
                         {return IsSelected(obj,selectionLevel,0);}
  virtual Int_t IsSelected(TObject* obj,Int_t selectionLevel,AliAODEvent* aod);

  Float_t GetMassCut(Int_t iPtBin=0) const { return (GetCuts() ? fCutsRD[GetGlobalIndex(0,iPtBin)] : 1.e6);}
  Float_t GetDCACut(Int_t iPtBin=0) const { return (GetCuts() ? fCutsRD[GetGlobalIndex(1,iPtBin)] : 1.e6);}
  Int_t CombineSelectionLevels(Int_t selectionvalTrack,Int_t selectionvalCand,Int_t selectionvalPID)const;
  virtual Bool_t IsInFiducialAcceptance(Double_t pt,Double_t y) const;
  virtual void SetStandardCutsPP2010();
  virtual void SetStandardCutsPP2011_276TeV();
  virtual void SetStandardCutsPbPb2010();
  virtual void SetStandardCutsPbPb2011();
  void SetStandardCutsPbPb2010Peripherals();
  virtual Int_t IsSelectedPID(AliAODRecoDecayHF *rd);
  Int_t IsSelectedPIDdefault(AliAODRecoDecayHF *rd);
  Int_t IsSelectedSpecialCuts(AliAODRecoDecayHF *d) const;
  void SetUseSpecialCuts(Bool_t useSpecialCuts) {fUseSpecialCuts=useSpecialCuts;}
  void SetMaximumPtSpecialCuts(Double_t pt) { fPtMaxSpecialCuts=pt; }
  void SetMaximumPforPID(Double_t p){fmaxPtrackForPID=p;}
  Double_t GetMaximumPforPID(){return fmaxPtrackForPID;}
  Double_t GetMaximumPtSpecialCuts() const { return fPtMaxSpecialCuts; }
  void SetLowPt(Bool_t lowpt,Double_t ptlow=2.) {fLowPt=lowpt;fPtLowPID=ptlow;}
  Bool_t GetUseSpecialCuts() const {return fUseSpecialCuts;}
  void SetUseDefaultPID(Bool_t defPID){fDefaultPID=defPID;}
  Bool_t GetIsUsedDefPID(){return fDefaultPID;}
  Double_t GetPtForPIDtight()const {return fPtLowPID;}
  void SetUseKF(Bool_t useKF);
  Bool_t GetIsUsedKF() const {return fUseKF;}

 
 protected:
  Int_t IsSelectedKF(AliAODRecoDecayHF2Prong* d,AliAODEvent* aod) const;

  Bool_t fUseSpecialCuts;  // flag to switch on/off special cuts
  Bool_t fLowPt;           // flag to switch on/off different pid for low pt D0
  Bool_t fDefaultPID;      // flag to switch on/off the default pid
  Bool_t fUseKF;           // flag to switch on/off D0 selection via KF 
  Double_t fPtLowPID;      // transverse momentum below which the strong PID is applied
  Double_t fPtMaxSpecialCuts; // transverse momentum below which the special cuts are applied
                              //  if set to zero, used for all pt
  Double_t  fmaxPtrackForPID; // max momentum for applying PID

  ClassDef(AliRDHFCutsD0toKpi,8);  // class for cuts on AOD reconstructed D0->Kpi
};

#endif

