#ifndef __TREEMAKER_H__
#define __TREEMAKER_H__

// --- need to check all these includes...
#include <fun4all/SubsysReco.h>
#include <vector>

#include "TTree.h"
#include "TFile.h"

class PHCompositeNode;

class TreeMaker: public SubsysReco
{

 public:

  TreeMaker(const std::string &name="TreeMaker.root", int embed_id = 0);

  int Init(PHCompositeNode*);
  int process_event(PHCompositeNode*);
  int End(PHCompositeNode*);

 private:

  TFile *_f;

  TTree *_tree;

  std::string _foutname;

  int _embed_id;

  static const int nJets = 200;
  static const int nJets_truth = 50;

  int _b_tjet2_n;
  float _b_tjet2_pt[nJets_truth];
  float _b_tjet2_eta[nJets_truth];
  float _b_tjet2_phi[nJets_truth];

  int _b_tjet3_n;
  float _b_tjet3_pt[nJets_truth];
  float _b_tjet3_eta[nJets_truth];
  float _b_tjet3_phi[nJets_truth];

  int _b_tjet4_n;
  float _b_tjet4_pt[nJets_truth];
  float _b_tjet4_eta[nJets_truth];
  float _b_tjet4_phi[nJets_truth];

  int _b_tjet5_n;
  float _b_tjet5_pt[nJets_truth];
  float _b_tjet5_eta[nJets_truth];
  float _b_tjet5_phi[nJets_truth];

  int _b_cjet2_n;
  float _b_cjet2_pt[nJets];
  float _b_cjet2_eta[nJets];
  float _b_cjet2_phi[nJets];

  int _b_cjet3_n;
  float _b_cjet3_pt[nJets];
  float _b_cjet3_eta[nJets];
  float _b_cjet3_phi[nJets];

  int _b_cjet4_n;
  float _b_cjet4_pt[nJets];
  float _b_cjet4_eta[nJets];
  float _b_cjet4_phi[nJets];

  int _b_cjet5_n;
  float _b_cjet5_pt[nJets];
  float _b_cjet5_eta[nJets];
  float _b_cjet5_phi[nJets];

  int _b_ljet2_n;
  float _b_ljet2_pt[nJets];
  float _b_ljet2_eta[nJets];
  float _b_ljet2_phi[nJets];

  int _b_ljet3_n;
  float _b_ljet3_pt[nJets];
  float _b_ljet3_eta[nJets];
  float _b_ljet3_phi[nJets];

  int _b_ljet4_n;
  float _b_ljet4_pt[nJets];
  float _b_ljet4_eta[nJets];
  float _b_ljet4_phi[nJets];

  int _b_ljet5_n;
  float _b_ljet5_pt[nJets];
  float _b_ljet5_eta[nJets];
  float _b_ljet5_phi[nJets];

  int _b_pjet2_n;
  float _b_pjet2_pt[nJets];
  float _b_pjet2_eta[nJets];
  float _b_pjet2_phi[nJets];

  int _b_pjet3_n;
  float _b_pjet3_pt[nJets];
  float _b_pjet3_eta[nJets];
  float _b_pjet3_phi[nJets];

  int _b_pjet4_n;
  float _b_pjet4_pt[nJets];
  float _b_pjet4_eta[nJets];
  float _b_pjet4_phi[nJets];

  int _b_pjet5_n;
  float _b_pjet5_pt[nJets];
  float _b_pjet5_eta[nJets];
  float _b_pjet5_phi[nJets];

  int _b_particle_n;
  float _b_particle_pt[1000];
  float _b_particle_eta[1000];
  float _b_particle_phi[1000];
  int _b_particle_pid[1000];
  int _b_particle_embed[1000];

};

#endif // __TREEMAKER_H__
