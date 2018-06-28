#ifndef AliAnalysisTaskSigma0Run2_H
#define AliAnalysisTaskSigma0Run2_H

#include "AliAnalysisTaskSE.h"
#include "AliConvEventCuts.h"
#include "AliEventCuts.h"
#include "AliMCEvent.h"
#include "AliSigma0PhotonMotherCuts.h"
#include "AliSigma0V0Cuts.h"
#include "AliStack.h"
#include "AliV0ReaderV1.h"
#include "TChain.h"

class AliVParticle;
class AliVTrack;

class AliAnalysisTaskSigma0Run2 : public AliAnalysisTaskSE {
 public:
  AliAnalysisTaskSigma0Run2();
  AliAnalysisTaskSigma0Run2(const char *name);
  virtual ~AliAnalysisTaskSigma0Run2() {}

  virtual void UserCreateOutputObjects();
  virtual void UserExec(Option_t *option);

  void SetV0ReaderName(TString name) { fV0ReaderName = name; }
  void SetIsHeavyIon(bool isHeavyIon) { fIsHeavyIon = isHeavyIon; }
  void SetIsMC(bool isMC) { fIsMC = isMC; }
  void SetLightweight(bool isLightweight) { fIsLightweight = isLightweight; }
  void SetV0Percentile(float v0perc) { fV0PercentileMax = v0perc; }
  void SetTrigger(UInt_t trigger) { fTrigger = trigger; }
  void SetV0Cuts(AliSigma0V0Cuts *cuts) { fV0Cuts = cuts; }
  void SetAntiV0Cuts(AliSigma0V0Cuts *cuts) { fAntiV0Cuts = cuts; }
  void SetPhotonV0Cuts(AliSigma0V0Cuts *cuts) { fPhotonV0Cuts = cuts; }
  void SetSigmaCuts(AliSigma0PhotonMotherCuts *cuts) { fSigmaCuts = cuts; }
  void SetAntiSigmaCuts(AliSigma0PhotonMotherCuts *cuts) {
    fAntiSigmaCuts = cuts;
  }
  void SetSigmaPhotonCuts(AliSigma0PhotonMotherCuts *cuts) {
    fSigmaPhotonCuts = cuts;
  }
  void SetAntiSigmaPhotonCuts(AliSigma0PhotonMotherCuts *cuts) {
    fAntiSigmaPhotonCuts = cuts;
  }

  bool AcceptEvent(AliVEvent *event);
  void CastToVector(std::vector<AliSigma0ParticleV0> &container,
                    const AliVEvent *inputEvent);
  void FillTriggerHisto(TH1F *histo);

  AliEventCuts fAliEventCuts;

 private:
  AliAnalysisTaskSigma0Run2(const AliAnalysisTaskSigma0Run2 &task);
  AliAnalysisTaskSigma0Run2 &operator=(const AliAnalysisTaskSigma0Run2 &task);

  AliVEvent *fInputEvent;                       //! current event
  AliMCEvent *fMCEvent;                         //! corresponding MC event
  AliV0ReaderV1 *fV0Reader;                     //! basic photon Selection Task
  TString fV0ReaderName;                        //
  AliSigma0V0Cuts *fV0Cuts;                     //
  AliSigma0V0Cuts *fAntiV0Cuts;                 //
  AliSigma0V0Cuts *fPhotonV0Cuts;               //
  AliSigma0PhotonMotherCuts *fSigmaCuts;        //
  AliSigma0PhotonMotherCuts *fAntiSigmaCuts;    //
  AliSigma0PhotonMotherCuts *fSigmaPhotonCuts;  //
  AliSigma0PhotonMotherCuts *fAntiSigmaPhotonCuts;  //

  bool fIsMC;              //
  bool fIsHeavyIon;        //
  bool fIsLightweight;     //
  float fV0PercentileMax;  //
  UInt_t fTrigger;         //

  std::vector<AliSigma0ParticleV0> fLambdaContainer;
  std::vector<AliSigma0ParticleV0> fAntiLambdaContainer;
  std::vector<AliSigma0ParticleV0> fPhotonV0Container;
  TClonesArray *fGammaArray;

  TList *fOutputContainer;                  //!
  TList *fQA;                               //!
  TH1F *fHistCutQA;                         //
  TProfile *fHistRunNumber;                 //
  TProfile *fHistCutBooking;                //
  TH1F *fHistCentralityProfileBefore;       //
  TH1F *fHistCentralityProfileAfter;        //
  TH1F *fHistCentralityProfileCoarseAfter;  //
  TH1F *fHistTriggerBefore;                 //
  TH1F *fHistTriggerAfter;                  //

  // Histograms
  // =====================================================================

  ClassDef(AliAnalysisTaskSigma0Run2, 2)
};
#endif
