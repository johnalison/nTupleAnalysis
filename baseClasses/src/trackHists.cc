#include "nTupleAnalysis/baseClasses/interface/trackHists.h"

using namespace nTupleAnalysis;

trackHists::trackHists(std::string name, fwlite::TFileService& fs, std::string title) {
  TFileDirectory dir = fs.mkdir(name);
  this->makeHists(name, dir, title);
}

trackHists::trackHists(std::string name, TFileDirectory& dir, std::string title) {
  this->makeHists(name, dir, title);
}


void trackHists::makeHists(std::string name, TFileDirectory& dir, std::string title) {
  v = new fourVectorHists(name, dir, title);

  ip3d_l = dir.make<TH1F>("ip3d_l","ip3d;IP3D [cm]",100,-0.2,0.2);
  ip3d   = dir.make<TH1F>("ip3d",  "ip3d;IP3D [cm]",100,-0.05,0.05);
  
  ip3d_sig_l = dir.make<TH1F>("ip3d_sig_l","ip3d sig;IP3D significance",100,-100,100);
  ip3d_sig   = dir.make<TH1F>("ip3d_sig",  "ip3d sig;IP3D significance",100,-10,10);
  
  ip3d_err_l = dir.make<TH1F>("ip3d_err_l","ip3d err;IP3D uncertianty [cm]",100,-0.01,0.1);
  ip3d_err   = dir.make<TH1F>("ip3d_err",  "ip3d err;IP3D uncertianty [cm]",100,-0.001,0.01);
  
  ip2d_l = dir.make<TH1F>("ip2d_l","ip2d;IP2D [cm]",100,-0.2,0.2);
  ip2d   = dir.make<TH1F>("ip2d",  "ip2d;IP2D [cm]",100,-0.05,0.05);

            
  Double_t nBinsPt[11] = {0,2,4,6,8,10,15,20,30,40,60};
  ip2d_vs_pt   = dir.make<TH2F>("ip2d_vs_pt",  "ip2d_vs_pt;P_T [GeV]; IP2D [cm]",10,nBinsPt,100,-0.03,0.03);

  Double_t nBinsEta[11] = {0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25, 2.5};
  ip2d_vs_eta   = dir.make<TH2F>("ip2d_vs_eta",  "ip2d_vs_eta;|#eta|; IP2D [cm]",10,nBinsEta,100,-0.03,0.03);


  ip2d_sig_l = dir.make<TH1F>("ip2d_sig_l","ip2d sig;IP2D significance",100,-100,100);
  ip2d_sig   = dir.make<TH1F>("ip2d_sig",  "ip2d sig;IP2D significance",100,-10,10);
        
  ip2d_err_l = dir.make<TH1F>("ip2d_err_l","ip2d err;IP2D uncertianty [cm]",100,-0.01,0.1);
  ip2d_err   = dir.make<TH1F>("ip2d_err",  "ip2d err;IP2D uncertianty [cm]",100,-0.001,0.01);
    
  trackDecayLenVal_l         = dir.make<TH1F>("trackDecayLenVal_l"  ,    "trackDecayLenVal;trackDecayLenVal [cm];Entries", 100, -0.1,  5);
  trackDecayLenVal           = dir.make<TH1F>("trackDecayLenVal"    ,    "trackDecayLenVal;trackDecayLenVal [cm];Entries", 100, -0.1,  0.5);
  trackJetDistVal            = dir.make<TH1F>("trackJetDistVal"     ,    "trackJetDistVal;trackJetDistVal [cm];Entries",  100, -0.1,0.01);      
  trackPtRel                 = dir.make<TH1F>("trackPtRel"          ,    "trackPtRel;track p_{T} Rel [GeV];Entries", 100, -0.1, 7);          
  trackMomentum              = dir.make<TH1F>("trackMomentum"       ,    "trackMomentum;track momentum [GeV];Entries", 60, 0, 60);       


  Double_t binsPt[28] = {0.9, 1.116, 1.3838, 1.716, 2.1278, 2.6385, 3.2717, 4.0569, 5.0306, 6.2379, 7.735, 9.5914, 11.8933, 14.7477, 18.2872, 22.6761, 28.1183, 34.8667, 43.2347, 53.6111, 66.4777, 82.4324, 102.2162, 126.748, 157.1676, 194.8878, 241.6609, 299.6595};
  trackPt_logx               = dir.make<TH1F>("trackPt_logx", "trackPt;track p_{T} [GeV];Entries", 27, binsPt);
  
  trackEta                   = dir.make<TH1F>("trackEta"            ,    "trackEta;track #eta;Entries", 100, -2.6, 2.6);            
  trackPhi                   = dir.make<TH1F>("trackPhi"            ,    "trackPhi;track #phi;Entries", 100, -3.2, 3.2);            
  trackPPar                  = dir.make<TH1F>("trackPPar"           ,    "trackPPar;track PPar [GeV];Entries",60, 0, 60);           
  trackDeltaR                = dir.make<TH1F>("trackDeltaR"         ,    "trackDeltaR;track #DeltaR;Entries", 160, -0.05, 0.35);         
  trackEtaRel                = dir.make<TH1F>("trackEtaRel"         ,    "trackEtaRel;track Eta Rel;Entries", 100, 0, 7);         
  trackPtRatio               = dir.make<TH1F>("trackPtRatio"        ,    "trackPtRatio;track p_{T} Ratio;Entries", 100, -0.01, 0.3); 
  trackPParRatio             = dir.make<TH1F>("trackPParRatio"      ,    "trackPParRatio;track P Par Ratio;Entries", 100, 0.95, 1.02);  
  
  trackChi2                  = dir.make<TH1F>("trackChi2"            ,    "trackChi2;track Chi2;Entries", 100, -0.1, 6);            
  trackNTotalHits            = dir.make<TH1F>("trackNTotalHits"      ,    "trackNTotalHits;trackNTotalHits;Entries", 30, -0.5, 29.5);
  trackNPixelHits            = dir.make<TH1F>("trackNPixelHits"      ,    "trackNPixelHits;trackNPixelHits;Entries", 10, -0.5,  9.5);  
  trackNStripHits            = dir.make<TH1F>("trackNStripHits"      ,    "trackNStripHits;trackNStripHits;Entries", 30, -0.5, 39.5);  
  trackHasInnerPixHit        = dir.make<TH1F>("trackHasInnerPixHit"  ,    "trackHasInnerPixHit;trackHasInnerPixHit;Entries", 2, -0.5,  1.5);  
  
  
  nMatches = dir.make<TH1F>("track_nMatches", "track_nMatches;# of matched tracks;Entries", 6, -0.5, 5.5);
  
  track_matched_dip2d     = dir.make<TH1F>("track_matched_dip2d"    ,    "track_matched_dip2d;IP2D-IP2D^{matched} [cm];Entries",100,-0.05,0.05);
  track_matched_phi_vs_dip2d = dir.make<TH2F>("track_matched_phi_vs_dip2d", "track_matched_phi_vs_dip2d;#phi;IP2D-IP2D^{matched} [cm]", 64,-3.2,3.2, 40,-0.02,0.02);
  track_matched_eta_vs_dip2d = dir.make<TH2F>("track_matched_eta_vs_dip2d", "track_matched_eta_vs_dip2d;#eta;IP2D-IP2D^{matched} [cm]", 52,-2.6,2.6, 40,-0.02,0.02);
  track_matched_dPtRel    = dir.make<TH1F>("track_matched_dPtRel"   ,    "track_matched_dPtRel;p_{T}^{Rel}-p_{T}^{Rel, matched} [GeV];Entries", 100, -5, 5);
  track_matched_dMomentum = dir.make<TH1F>("track_matched_dMomentum",    "track_matched_dMomentum;p-p^{matched} [GeV];Entries", 500, -10, 10);
  track_matched_dEta      = dir.make<TH1F>("track_matched_dEta"     ,    "track_matched_dEta;#eta-#eta^{matched};Entries", 500, -0.1, 0.1);            
  track_matched_dEta_s    = dir.make<TH1F>("track_matched_dEta_s"   ,    "track_matched_dEta;#eta-#eta^{matched};Entries", 500, -0.01, 0.01);            
  track_matched_dPhi      = dir.make<TH1F>("track_matched_dPhi"     ,    "track_matched_dPhi;#phi-#phi^{matched};Entries", 500,     0, 0.1);            
  track_matched_dR        = dir.make<TH1F>("track_matched_dR"       ,    "track_matched_dR;#DeltaR(track, matched track);;Entries", 500, -0.05, 1.2);
  track_matched_dR_s      = dir.make<TH1F>("track_matched_dR_s"     ,    "track_matched_dR;#DeltaR(track, matched track);;Entries", 340, -0.005, 0.08);
  
  track_matched_dEta_vs_dMomentum = dir.make<TH2F>("track_matched_dEta_vs_dMomentum", "dEta_vs_dMomentum;#eta-#eta^{matched};p-p^{matched} [GeV]",100,-0.01,0.01,100,-5,5);
  track_matched_dEta_vs_dPhi = dir.make<TH2F>("track_matched_dEta_vs_dPhi", "dEta_vs_dPhi;#eta-#eta^{matched};|#phi-#phi^{matched}|",120,-0.012,0.012,60,0,0.012);

  track_secondClosest_dEta      = dir.make<TH1F>("track_secondClosest_dEta",         "track_matched_dEta2;#eta-#eta^{second closest};Entries", 500, -0.1, 0.1);
  track_secondClosest_dEta_s    = dir.make<TH1F>("track_secondClosest_dEta_s",       "track_matched_dEta2;#eta-#eta^{second closest};Entries", 500, -0.01, 0.01);
  track_secondClosest_dMomentum = dir.make<TH1F>("track_secondClosest_dMomentum",    "track_secondClosest_dMomentum;p-p^{second closest} [GeV];Entries", 500, -10, 10);
  track_secondClosest_dR        = dir.make<TH1F>("track_secondClosest_dR"       ,    "track_secondClosest_dR;#DeltaR(matched track, secondClosest track);;Entries", 500, -0.05, 1.2);
  track_secondClosest_dR_s      = dir.make<TH1F>("track_secondClosest_dR_s"     ,    "track_secondClosest_dR;#DeltaR(matched track, secondClosest track);;Entries", 340, -0.005, 0.08);
  track_secondClosest_dEta_vs_dMomentum = dir.make<TH2F>("track_secondClosest_dEta_vs_dMomentum", "dEta_vs_dMomentum;#eta-#eta^{secondClosest};p-p^{secondClosest} [GeV]",100,-0.01,0.01,100,-5,5);
  track_dEta12 = dir.make<TH1F>("track_dEta12", "track_dEta12;#eta^{matched}-#eta^{second closest};Entries", 500, -0.1, 0.1);

  nTracks         = dir.make<TH1F>("nTracks",     ("nTracks;    " +title+" Number of Tracks; Entries").c_str(),  10,-0.5,9.5);
  trackCharge     = dir.make<TH1F>("charge",     ("charge;    " +title+" Charge; Entries").c_str(),  3,-1.5,1.5);
  trackIsFromSV   = dir.make<TH1F>("IsFromSV"  ,  "IsFromSV;Is from SV;Entries", 2, -0.5,  1.5);  
  trackIsFromV0   = dir.make<TH1F>("IsFromV0"  ,  "IsFromV0;Is from V0;Entries", 2, -0.5,  1.5);  
  trackAlgo       = dir.make<TH1F>("algo"  ,  "Algo;Track Algo", 40, -0.5,  39.5);  
  trackOrigAlgo       = dir.make<TH1F>("origAlgo"  ,  "origAlgo;Track Original Algo", 40, -0.5,  39.5);  
} 

void trackHists::Fill(std::shared_ptr<track> &track, float weight){

  v->Fill(track->p, weight);

  ip3d  ->Fill(track->IP);
  ip3d_l->Fill(track->IP);
        
  ip3d_sig  ->Fill(track->IPsig);
  ip3d_sig_l->Fill(track->IPsig);
  
  ip3d_err  ->Fill(track->IPerr);
  ip3d_err_l->Fill(track->IPerr);
  
  ip2d  ->Fill(track->IP2D);
  ip2d_l->Fill(track->IP2D);
  
  ip2d_sig  ->Fill(track->IP2Dsig);
  ip2d_sig_l->Fill(track->IP2Dsig);
  
  ip2d_err  ->Fill(track->IPerr);
  ip2d_err_l->Fill(track->IPerr);

  float pt = track->p.Pt();
  float eta = track->p.Eta();

  ip2d_vs_pt->Fill(     pt, track->IP2D);
  ip2d_vs_eta->Fill(fabs(eta)    , track->IP2D);
        

  trackDecayLenVal_l   ->Fill(track->length);
  trackDecayLenVal     ->Fill(track->length);
  trackJetDistVal      ->Fill(track->dist );
  //trackPtRel           ->Fill(track->ptRel      );

  trackMomentum        ->Fill(pt   ); 
  trackPt_logx         ->Fill(pt         ); 
  trackEta             ->Fill(eta        );
  trackPhi             ->Fill(track->p.Phi()        );
  //trackPPar            ->Fill(track->pPar       );
  //trackDeltaR          ->Fill(track->dR         );
  //trackEtaRel          ->Fill(track->etaRel     );
  //trackPtRatio         ->Fill(track->ptRatio    );
  //trackPParRatio       ->Fill(track->pParRatio  );

  trackChi2                  ->Fill(track->chi2      );
  trackNTotalHits            ->Fill(track->nHitAll); 
  trackNPixelHits            ->Fill(track->nHitPixel);
  trackNStripHits            ->Fill(track->nHitStrip);
  trackHasInnerPixHit        ->Fill(track->isHitL1);

  trackCharge          ->Fill(track->charge        );
  trackIsFromSV        ->Fill(track->isfromSV);
  trackIsFromV0        ->Fill(track->isfromV0);
  trackAlgo            ->Fill(track->algo);
  trackOrigAlgo        ->Fill(track->originalAlgo);

  if(track->matchedTrack != nullptr){
    track_matched_dip2d       ->Fill(            track->IP2D  - track->matchedTrack->IP2D);
    track_matched_phi_vs_dip2d->Fill(track->phi, track->IP2D  - track->matchedTrack->IP2D);
    track_matched_eta_vs_dip2d->Fill(track->eta, track->IP2D  - track->matchedTrack->IP2D);
    //track_matched_dPtRel   ->Fill(track.ptRel    - track.matchedTrack->ptRel);
    
    float dPt = track->pt - track->matchedTrack->pt; 
    track_matched_dMomentum->Fill(dPt);
    float dEta = track->eta      - track->matchedTrack->eta;
    track_matched_dEta     ->Fill(dEta, weight);
    track_matched_dEta_s   ->Fill(dEta, weight);
    float dPhi = track->p.DeltaPhi(track->matchedTrack->p);
    track_matched_dPhi     ->Fill(dPhi);

    //float matched_dEta = (track.eta-track.matchedTrack->eta);
    float dR   = track->p.DeltaR(track->matchedTrack->p);
    track_matched_dR       ->Fill(dR, weight);
    track_matched_dR_s     ->Fill(dR, weight);
    
    track_matched_dEta_vs_dMomentum->Fill(dEta, dPt);
    track_matched_dEta_vs_dPhi     ->Fill(dEta, dPhi);
  }

  if(track->secondClosest != nullptr){
    track_secondClosest_dEta     ->Fill(track->eta      - track->secondClosest->eta);
    track_secondClosest_dEta_s   ->Fill(track->eta      - track->secondClosest->eta);
    track_secondClosest_dMomentum->Fill(track->pt - track->secondClosest->pt); 

    float secondClosest_dEta = track->eta-track->secondClosest->eta;
    //float secondClosest_dPhi = track->p.DeltaPhi(track->secondClosest->p);
    float secondClosest_dR   = track->p.DeltaR(track->secondClosest->p);
    track_secondClosest_dR       ->Fill(secondClosest_dR);
    track_secondClosest_dR_s     ->Fill(secondClosest_dR);
    track_secondClosest_dEta_vs_dMomentum->Fill(secondClosest_dEta, track->pt - track->secondClosest->pt);
    track_dEta12->Fill(track->matchedTrack->eta - track->secondClosest->eta);
 }


  return;
}

void 
trackHists::FillMatchStats (std::shared_ptr<track> &track, float weight){
  nMatches->Fill(track->nMatches, weight);
  return;
}


trackHists::~trackHists(){} 