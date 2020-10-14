#include "TreeMaker.h"

#include <phool/getClass.h>
#include <fun4all/Fun4AllServer.h>

#include <phool/PHCompositeNode.h>

#include "TLorentzVector.h"
#include <iostream>

#include <g4jets/JetMap.h>
#include <g4jets/Jet.h>

#include <g4main/PHG4TruthInfoContainer.h>
#include <g4main/PHG4Particle.h>

#include <phhepmc/PHHepMCGenEvent.h>
#include <phhepmc/PHHepMCGenEventMap.h>


TreeMaker::TreeMaker(const std::string &name, int embed_id) : SubsysReco("TREEMAKER")
{

  _foutname = name;
  _embed_id = embed_id;

}


int TreeMaker::Init(PHCompositeNode *topNode)
{

  _f = new TFile( _foutname.c_str(), "RECREATE");

  std::cout << " making a file = " <<  _foutname.c_str() << " , _f = " << _f << std::endl;
  
  _tree = new TTree("ttree","a persevering date tree");
  
  std::cout << " tree is at " << _tree << std::endl;

  _tree->Branch("tjet2_n", &_b_tjet2_n,"tjet2_n/I");
  _tree->Branch("tjet2_pt", _b_tjet2_pt,"tjet2_pt[tjet2_n]/F");
  _tree->Branch("tjet2_eta", _b_tjet2_eta,"tjet2_eta[tjet2_n]/F");
  _tree->Branch("tjet2_phi", _b_tjet2_phi,"tjet2_phi[tjet2_n]/F");

  _tree->Branch("cjet2_n", &_b_cjet2_n,"cjet2_n/I");
  _tree->Branch("cjet2_pt", _b_cjet2_pt,"cjet2_pt[cjet2_n]/F");
  _tree->Branch("cjet2_eta", _b_cjet2_eta,"cjet2_eta[cjet2_n]/F");
  _tree->Branch("cjet2_phi", _b_cjet2_phi,"cjet2_phi[cjet2_n]/F");

  _tree->Branch("ljet2_n", &_b_ljet2_n,"ljet2_n/I");
  _tree->Branch("ljet2_pt", _b_ljet2_pt,"ljet2_pt[ljet2_n]/F");
  _tree->Branch("ljet2_eta", _b_ljet2_eta,"ljet2_eta[ljet2_n]/F");
  _tree->Branch("ljet2_phi", _b_ljet2_phi,"ljet2_phi[ljet2_n]/F");

  _tree->Branch("pjet2_n", &_b_pjet2_n,"pjet2_n/I");
  _tree->Branch("pjet2_pt", _b_pjet2_pt,"pjet2_pt[pjet2_n]/F");
  _tree->Branch("pjet2_eta", _b_pjet2_eta,"pjet2_eta[pjet2_n]/F");
  _tree->Branch("pjet2_phi", _b_pjet2_phi,"pjet2_phi[pjet2_n]/F");

  _tree->Branch("tjet3_n", &_b_tjet3_n,"tjet3_n/I");
  _tree->Branch("tjet3_pt", _b_tjet3_pt,"tjet3_pt[tjet3_n]/F");
  _tree->Branch("tjet3_eta", _b_tjet3_eta,"tjet3_eta[tjet3_n]/F");
  _tree->Branch("tjet3_phi", _b_tjet3_phi,"tjet3_phi[tjet3_n]/F");

  _tree->Branch("cjet3_n", &_b_cjet3_n,"cjet3_n/I");
  _tree->Branch("cjet3_pt", _b_cjet3_pt,"cjet3_pt[cjet3_n]/F");
  _tree->Branch("cjet3_eta", _b_cjet3_eta,"cjet3_eta[cjet3_n]/F");
  _tree->Branch("cjet3_phi", _b_cjet3_phi,"cjet3_phi[cjet3_n]/F");

  _tree->Branch("ljet3_n", &_b_ljet3_n,"ljet3_n/I");
  _tree->Branch("ljet3_pt", _b_ljet3_pt,"ljet3_pt[ljet3_n]/F");
  _tree->Branch("ljet3_eta", _b_ljet3_eta,"ljet3_eta[ljet3_n]/F");
  _tree->Branch("ljet3_phi", _b_ljet3_phi,"ljet3_phi[ljet3_n]/F");

  _tree->Branch("pjet3_n", &_b_pjet3_n,"pjet3_n/I");
  _tree->Branch("pjet3_pt", _b_pjet3_pt,"pjet3_pt[pjet3_n]/F");
  _tree->Branch("pjet3_eta", _b_pjet3_eta,"pjet3_eta[pjet3_n]/F");
  _tree->Branch("pjet3_phi", _b_pjet3_phi,"pjet3_phi[pjet3_n]/F");

  _tree->Branch("tjet4_n", &_b_tjet4_n,"tjet4_n/I");
  _tree->Branch("tjet4_pt", _b_tjet4_pt,"tjet4_pt[tjet4_n]/F");
  _tree->Branch("tjet4_eta", _b_tjet4_eta,"tjet4_eta[tjet4_n]/F");
  _tree->Branch("tjet4_phi", _b_tjet4_phi,"tjet4_phi[tjet4_n]/F");

  _tree->Branch("cjet4_n", &_b_cjet4_n,"cjet4_n/I");
  _tree->Branch("cjet4_pt", _b_cjet4_pt,"cjet4_pt[cjet4_n]/F");
  _tree->Branch("cjet4_eta", _b_cjet4_eta,"cjet4_eta[cjet4_n]/F");
  _tree->Branch("cjet4_phi", _b_cjet4_phi,"cjet4_phi[cjet4_n]/F");

  _tree->Branch("ljet4_n", &_b_ljet4_n,"ljet4_n/I");
  _tree->Branch("ljet4_pt", _b_ljet4_pt,"ljet4_pt[ljet4_n]/F");
  _tree->Branch("ljet4_eta", _b_ljet4_eta,"ljet4_eta[ljet4_n]/F");
  _tree->Branch("ljet4_phi", _b_ljet4_phi,"ljet4_phi[ljet4_n]/F");

  _tree->Branch("pjet4_n", &_b_pjet4_n,"pjet4_n/I");
  _tree->Branch("pjet4_pt", _b_pjet4_pt,"pjet4_pt[pjet4_n]/F");
  _tree->Branch("pjet4_eta", _b_pjet4_eta,"pjet4_eta[pjet4_n]/F");
  _tree->Branch("pjet4_phi", _b_pjet4_phi,"pjet4_phi[pjet4_n]/F");

  _tree->Branch("tjet5_n", &_b_tjet5_n,"tjet5_n/I");
  _tree->Branch("tjet5_pt", _b_tjet5_pt,"tjet5_pt[tjet5_n]/F");
  _tree->Branch("tjet5_eta", _b_tjet5_eta,"tjet5_eta[tjet5_n]/F");
  _tree->Branch("tjet5_phi", _b_tjet5_phi,"tjet5_phi[tjet5_n]/F");

  _tree->Branch("cjet5_n", &_b_cjet5_n,"cjet5_n/I");
  _tree->Branch("cjet5_pt", _b_cjet5_pt,"cjet5_pt[cjet5_n]/F");
  _tree->Branch("cjet5_eta", _b_cjet5_eta,"cjet5_eta[cjet5_n]/F");
  _tree->Branch("cjet5_phi", _b_cjet5_phi,"cjet5_phi[cjet5_n]/F");

  _tree->Branch("ljet5_n", &_b_ljet5_n,"ljet5_n/I");
  _tree->Branch("ljet5_pt", _b_ljet5_pt,"ljet5_pt[ljet5_n]/F");
  _tree->Branch("ljet5_eta", _b_ljet5_eta,"ljet5_eta[ljet5_n]/F");
  _tree->Branch("ljet5_phi", _b_ljet5_phi,"ljet5_phi[ljet5_n]/F");

  _tree->Branch("pjet5_n", &_b_pjet5_n,"pjet5_n/I");
  _tree->Branch("pjet5_pt", _b_pjet5_pt,"pjet5_pt[pjet5_n]/F");
  _tree->Branch("pjet5_eta", _b_pjet5_eta,"pjet5_eta[pjet5_n]/F");
  _tree->Branch("pjet5_phi", _b_pjet5_phi,"pjet5_phi[pjet5_n]/F");

  _tree->Branch("particle_n", &_b_particle_n,"particle_n/I");
  _tree->Branch("particle_pt", _b_particle_pt,"particle_pt[particle_n]/F");
  _tree->Branch("particle_eta", _b_particle_eta,"particle_eta[particle_n]/F");
  _tree->Branch("particle_phi", _b_particle_phi,"particle_phi[particle_n]/F");
  _tree->Branch("particle_pid", _b_particle_pid,"particle_pid[particle_n]/I");

  return 0;

}

int TreeMaker::process_event(PHCompositeNode *topNode)
{

  std::cout << "TreeMaker : at process_event, tree size is: " << _tree->GetEntries() << std::endl;


  ////////////////////////////////////////////////////////
  // R=0.2
  _b_tjet2_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Truth_r02");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet2_pt = this_jet->get_pt();
      float jet2_phi = this_jet->get_phi();
      float jet2_eta = this_jet->get_eta();

      _b_tjet2_pt[ _b_tjet2_n ] = jet2_pt;
      _b_tjet2_eta[ _b_tjet2_n ] = jet2_eta;
      _b_tjet2_phi[ _b_tjet2_n ] = jet2_phi;

      if (this_jet->get_pt() < 5 || fabs(jet2_eta) > 0.6) continue;

      //std::cout << " Truth R=0.2 jet #" << _b_tjet2_n << ", pt / eta / phi = " << jet2_pt << " / " << jet2_eta << " / " << jet2_phi << std::endl;

      _b_tjet2_n++;
    }
  }

  _b_cjet2_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Tower_r02");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet2_pt = this_jet->get_pt();
      float jet2_phi = this_jet->get_phi();
      float jet2_eta = this_jet->get_eta();

      _b_cjet2_pt[ _b_cjet2_n ] = jet2_pt;
      _b_cjet2_eta[ _b_cjet2_n ] = jet2_eta;
      _b_cjet2_phi[ _b_cjet2_n ] = jet2_phi;

      if (this_jet->get_pt() < 5 || fabs(jet2_eta) > 0.6) continue;

      //std::cout << " Tower R=0.2 jet #" << _b_cjet2_n << ", pt / eta / phi = " << jet2_pt << " / " << jet2_eta << " / " << jet2_phi << std::endl;

      _b_cjet2_n++;
    }
  }

  _b_ljet2_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Cluster_r02");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet2_pt = this_jet->get_pt();
      float jet2_phi = this_jet->get_phi();
      float jet2_eta = this_jet->get_eta();

      _b_ljet2_pt[ _b_ljet2_n ] = jet2_pt;
      _b_ljet2_eta[ _b_ljet2_n ] = jet2_eta;
      _b_ljet2_phi[ _b_ljet2_n ] = jet2_phi;

      if (this_jet->get_pt() < 5 || fabs(jet2_eta) > 0.6) continue;

      //std::cout << " Tower R=0.2 jet #" << _b_ljet2_n << ", pt / eta / phi = " << jet2_pt << " / " << jet2_eta << " / " << jet2_phi << std::endl;

      _b_ljet2_n++;
    }
  }

  _b_pjet2_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_ParticleFlow_r02");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet2_pt = this_jet->get_pt();
      float jet2_phi = this_jet->get_phi();
      float jet2_eta = this_jet->get_eta();

      _b_pjet2_pt[ _b_pjet2_n ] = jet2_pt;
      _b_pjet2_eta[ _b_pjet2_n ] = jet2_eta;
      _b_pjet2_phi[ _b_pjet2_n ] = jet2_phi;

      if (this_jet->get_pt() < 5 || fabs(jet2_eta) > 0.6) continue;

      //std::cout << " ParticleFlow R=0.2 jet #" << _b_pjet2_n << ", pt / eta / phi = " << jet2_pt << " / " << jet2_eta << " / " << jet2_phi << std::endl;

      _b_pjet2_n++;
    }
  }


  ////////////////////////////////////////////////////////
  // R=0.3
  _b_tjet3_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Truth_r03");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet3_pt = this_jet->get_pt();
      float jet3_phi = this_jet->get_phi();
      float jet3_eta = this_jet->get_eta();

      _b_tjet3_pt[ _b_tjet3_n ] = jet3_pt;
      _b_tjet3_eta[ _b_tjet3_n ] = jet3_eta;
      _b_tjet3_phi[ _b_tjet3_n ] = jet3_phi;

      if (this_jet->get_pt() < 5 || fabs(jet3_eta) > 0.6) continue;

      //std::cout << " Truth R=0.3 jet #" << _b_tjet3_n << ", pt / eta / phi = " << jet3_pt << " / " << jet3_eta << " / " << jet3_phi << std::endl;

      _b_tjet3_n++;
    }
  }

  _b_cjet3_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Tower_r03");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet3_pt = this_jet->get_pt();
      float jet3_phi = this_jet->get_phi();
      float jet3_eta = this_jet->get_eta();

      _b_cjet3_pt[ _b_cjet3_n ] = jet3_pt;
      _b_cjet3_eta[ _b_cjet3_n ] = jet3_eta;
      _b_cjet3_phi[ _b_cjet3_n ] = jet3_phi;

      if (this_jet->get_pt() < 5 || fabs(jet3_eta) > 0.6) continue;

      //std::cout << " Tower R=0.3 jet #" << _b_cjet3_n << ", pt / eta / phi = " << jet3_pt << " / " << jet3_eta << " / " << jet3_phi << std::endl;

      _b_cjet3_n++;
    }
  }

  _b_ljet3_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Cluster_r03");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet3_pt = this_jet->get_pt();
      float jet3_phi = this_jet->get_phi();
      float jet3_eta = this_jet->get_eta();

      _b_ljet3_pt[ _b_ljet3_n ] = jet3_pt;
      _b_ljet3_eta[ _b_ljet3_n ] = jet3_eta;
      _b_ljet3_phi[ _b_ljet3_n ] = jet3_phi;

      if (this_jet->get_pt() < 5 || fabs(jet3_eta) > 0.6) continue;

      //std::cout << " Tower R=0.3 jet #" << _b_ljet3_n << ", pt / eta / phi = " << jet3_pt << " / " << jet3_eta << " / " << jet3_phi << std::endl;

      _b_ljet3_n++;
    }
  }

  _b_pjet3_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_ParticleFlow_r03");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet3_pt = this_jet->get_pt();
      float jet3_phi = this_jet->get_phi();
      float jet3_eta = this_jet->get_eta();

      _b_pjet3_pt[ _b_pjet3_n ] = jet3_pt;
      _b_pjet3_eta[ _b_pjet3_n ] = jet3_eta;
      _b_pjet3_phi[ _b_pjet3_n ] = jet3_phi;

      if (this_jet->get_pt() < 5 || fabs(jet3_eta) > 0.6) continue;

      //std::cout << " ParticleFlow R=0.3 jet #" << _b_pjet3_n << ", pt / eta / phi = " << jet3_pt << " / " << jet3_eta << " / " << jet3_phi << std::endl;

      _b_pjet3_n++;
    }
  }


  ////////////////////////////////////////////////////////
  // R=0.4
  _b_tjet4_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Truth_r04");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet4_pt = this_jet->get_pt();
      float jet4_phi = this_jet->get_phi();
      float jet4_eta = this_jet->get_eta();

      _b_tjet4_pt[ _b_tjet4_n ] = jet4_pt;
      _b_tjet4_eta[ _b_tjet4_n ] = jet4_eta;
      _b_tjet4_phi[ _b_tjet4_n ] = jet4_phi;

      if (this_jet->get_pt() < 5 || fabs(jet4_eta) > 0.6) continue;

      //std::cout << " Truth R=0.4 jet #" << _b_tjet4_n << ", pt / eta / phi = " << jet4_pt << " / " << jet4_eta << " / " << jet4_phi << std::endl;

      _b_tjet4_n++;
    }
  }

  _b_cjet4_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Tower_r04");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet4_pt = this_jet->get_pt();
      float jet4_phi = this_jet->get_phi();
      float jet4_eta = this_jet->get_eta();

      _b_cjet4_pt[ _b_cjet4_n ] = jet4_pt;
      _b_cjet4_eta[ _b_cjet4_n ] = jet4_eta;
      _b_cjet4_phi[ _b_cjet4_n ] = jet4_phi;

      if (this_jet->get_pt() < 5 || fabs(jet4_eta) > 0.6) continue;

      //std::cout << " Tower R=0.4 jet #" << _b_cjet4_n << ", pt / eta / phi = " << jet4_pt << " / " << jet4_eta << " / " << jet4_phi << std::endl;

      _b_cjet4_n++;
    }
  }

  _b_ljet4_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Cluster_r04");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet4_pt = this_jet->get_pt();
      float jet4_phi = this_jet->get_phi();
      float jet4_eta = this_jet->get_eta();

      _b_ljet4_pt[ _b_ljet4_n ] = jet4_pt;
      _b_ljet4_eta[ _b_ljet4_n ] = jet4_eta;
      _b_ljet4_phi[ _b_ljet4_n ] = jet4_phi;

      if (this_jet->get_pt() < 5 || fabs(jet4_eta) > 0.6) continue;

      //std::cout << " Tower R=0.4 jet #" << _b_ljet4_n << ", pt / eta / phi = " << jet4_pt << " / " << jet4_eta << " / " << jet4_phi << std::endl;

      _b_ljet4_n++;
    }
  }

  _b_pjet4_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_ParticleFlow_r04");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet4_pt = this_jet->get_pt();
      float jet4_phi = this_jet->get_phi();
      float jet4_eta = this_jet->get_eta();

      _b_pjet4_pt[ _b_pjet4_n ] = jet4_pt;
      _b_pjet4_eta[ _b_pjet4_n ] = jet4_eta;
      _b_pjet4_phi[ _b_pjet4_n ] = jet4_phi;

      if (this_jet->get_pt() < 5 || fabs(jet4_eta) > 0.6) continue;

      //std::cout << " ParticleFlow R=0.4 jet #" << _b_pjet4_n << ", pt / eta / phi = " << jet4_pt << " / " << jet4_eta << " / " << jet4_phi << std::endl;

      _b_pjet4_n++;
    }
  }


  ////////////////////////////////////////////////////////
  // R=0.5
  _b_tjet5_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Truth_r05");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet5_pt = this_jet->get_pt();
      float jet5_phi = this_jet->get_phi();
      float jet5_eta = this_jet->get_eta();

      _b_tjet5_pt[ _b_tjet5_n ] = jet5_pt;
      _b_tjet5_eta[ _b_tjet5_n ] = jet5_eta;
      _b_tjet5_phi[ _b_tjet5_n ] = jet5_phi;

      if (this_jet->get_pt() < 5 || fabs(jet5_eta) > 0.6) continue;

      //std::cout << " Truth R=0.5 jet #" << _b_tjet5_n << ", pt / eta / phi = " << jet5_pt << " / " << jet5_eta << " / " << jet5_phi << std::endl;

      _b_tjet5_n++;
    }
  }

  _b_cjet5_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Tower_r05");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet5_pt = this_jet->get_pt();
      float jet5_phi = this_jet->get_phi();
      float jet5_eta = this_jet->get_eta();

      _b_cjet5_pt[ _b_cjet5_n ] = jet5_pt;
      _b_cjet5_eta[ _b_cjet5_n ] = jet5_eta;
      _b_cjet5_phi[ _b_cjet5_n ] = jet5_phi;

      if (this_jet->get_pt() < 5 || fabs(jet5_eta) > 0.6) continue;

      //std::cout << " Tower R=0.5 jet #" << _b_cjet5_n << ", pt / eta / phi = " << jet5_pt << " / " << jet5_eta << " / " << jet5_phi << std::endl;

      _b_cjet5_n++;
    }
  }

  _b_ljet5_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_Cluster_r05");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet5_pt = this_jet->get_pt();
      float jet5_phi = this_jet->get_phi();
      float jet5_eta = this_jet->get_eta();

      _b_ljet5_pt[ _b_ljet5_n ] = jet5_pt;
      _b_ljet5_eta[ _b_ljet5_n ] = jet5_eta;
      _b_ljet5_phi[ _b_ljet5_n ] = jet5_phi;

      if (this_jet->get_pt() < 5 || fabs(jet5_eta) > 0.6) continue;

      //std::cout << " Tower R=0.5 jet #" << _b_ljet5_n << ", pt / eta / phi = " << jet5_pt << " / " << jet5_eta << " / " << jet5_phi << std::endl;

      _b_ljet5_n++;
    }
  }

  _b_pjet5_n = 0;
  {
    JetMap* jets = findNode::getClass<JetMap>(topNode,"AntiKt_ParticleFlow_r05");

    for (JetMap::Iter iter = jets->begin(); iter != jets->end(); ++iter) {
      Jet* this_jet = iter->second;
      
      float jet5_pt = this_jet->get_pt();
      float jet5_phi = this_jet->get_phi();
      float jet5_eta = this_jet->get_eta();

      _b_pjet5_pt[ _b_pjet5_n ] = jet5_pt;
      _b_pjet5_eta[ _b_pjet5_n ] = jet5_eta;
      _b_pjet5_phi[ _b_pjet5_n ] = jet5_phi;

      if (this_jet->get_pt() < 5 || fabs(jet5_eta) > 0.6) continue;

      //std::cout << " ParticleFlow R=0.5 jet #" << _b_pjet5_n << ", pt / eta / phi = " << jet5_pt << " / " << jet5_eta << " / " << jet5_phi << std::endl;

      _b_pjet5_n++;
    }
  }


  /////////////////////////////////////////////////
  // true particle information
  _b_particle_n = 0;
  {
    
    PHG4TruthInfoContainer* truthinfo = findNode::getClass <PHG4TruthInfoContainer> (topNode, "G4TruthInfo");
    PHG4TruthInfoContainer::Range range = truthinfo->GetPrimaryParticleRange ();
    
    for (PHG4TruthInfoContainer::ConstIterator iter = range.first; iter != range.second; ++iter) {
      PHG4Particle* g4particle = iter->second;
      
      TLorentzVector t;
      t.SetPxPyPzE (g4particle->get_px (), g4particle->get_py (), g4particle->get_pz (), g4particle->get_e ());
      
      float truth_pt = t.Pt ();
      if (truth_pt < 0.1)
	continue; // only keep pt > 0.1
      
      float truth_eta = t.Eta ();
      if (fabs (truth_eta) > 1.1)
	continue; // only keep |eta| < 1.1
      
      float truth_phi = t.Phi ();
      int truth_pid = g4particle->get_pid (); // particle species
      

      // IMPORTANT! Pythia particles have an "embed id"=2, while Hijing particles will have "embed id"=0.
      // Think twice before writing out all pT > 0.4 GeV Hijing particles....
      //if (truthinfo->isEmbeded (g4particle->get_track_id ()) == 2) {
      _b_particle_pt[_b_particle_n] = truth_pt;
      _b_particle_eta[_b_particle_n] = truth_eta;
      _b_particle_phi[_b_particle_n] = truth_phi;
      _b_particle_pid[_b_particle_n] = truth_pid;
      
      _b_particle_embed[_b_particle_n] = truthinfo->isEmbeded (g4particle->get_track_id ());
      
      _b_particle_n++;
      
    //  if (  g4particle->get_e () > 1 ) 
	//std::cout << " Truth Particle #" << _b_particle_n << ", pt / eta / phi / E = " << truth_pt << " / " << truth_eta << " / " << truth_phi << " / " << g4particle->get_e () << " , PID " << truth_pid << ", embed = " << truthinfo->isEmbeded (g4particle->get_track_id ()) << std::endl;
      
    }
  }
      
  std::cout << " -------------------------- below is next event " <<  _tree->GetEntries() + 1 << std::endl;
  
  _tree->Fill();
  
  return 0;
}



int TreeMaker::End(PHCompositeNode *topNode)
{

  _f->Write();
  _f->Close();

  return 0;
}

