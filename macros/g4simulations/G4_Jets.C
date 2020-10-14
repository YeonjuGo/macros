#pragma once

#include "GlobalVariables.C"

#include <g4jets/ClusterJetInput.h>
//#include </sphenix/u/yeonjugo/Projects/sPHENIX_2ndfromDennis/install/include/g4jets/ClusterJetInput.h>
#include <g4jets/FastJetAlgo.h>
#include <g4jets/JetReco.h>
//#include </sphenix/u/yeonjugo/Projects/sPHENIX_2ndfromDennis/install/include/g4jets/JetReco.h>
#include <g4jets/TowerJetInput.h>
#include <g4jets/TrackJetInput.h>
#include <g4jets/TruthJetInput.h>

#include <g4eval/JetEvaluator.h>

#include <fun4all/Fun4AllServer.h>

R__LOAD_LIBRARY(libg4jets.so)
R__LOAD_LIBRARY(libg4eval.so)

namespace Enable
{
  bool JETS = false;
  bool JETS_EVAL = false;
  int JETS_VERBOSITY = 0;
}

void JetInit() {}

void Jet_Reco() {

int verbosity = std::max(Enable::VERBOSITY, Enable::JETS_VERBOSITY);

  Fun4AllServer *se = Fun4AllServer::instance();

  // truth particle level jets
  JetReco *truthjetreco = new JetReco("TRUTHJETRECO");
  truthjetreco->add_input(new TruthJetInput(Jet::PARTICLE));
  truthjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.2),"AntiKt_Truth_r02");
  truthjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.3),"AntiKt_Truth_r03");
  truthjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.4),"AntiKt_Truth_r04");
  truthjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.5),"AntiKt_Truth_r05");
  truthjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.6),"AntiKt_Truth_r06");
  truthjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.7),"AntiKt_Truth_r07");
  truthjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.8),"AntiKt_Truth_r08");
  truthjetreco->set_algo_node("ANTIKT");
  truthjetreco->set_input_node("TRUTH");
  truthjetreco->Verbosity(verbosity);
  se->registerSubsystem(truthjetreco);

  // tower jets
  JetReco *towerjetreco = new JetReco("TOWERJETRECO");
  towerjetreco->add_input(new TowerJetInput(Jet::CEMC_TOWER));
  towerjetreco->add_input(new TowerJetInput(Jet::HCALIN_TOWER));
  towerjetreco->add_input(new TowerJetInput(Jet::HCALOUT_TOWER));
  towerjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.2),"AntiKt_Tower_r02");
  towerjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.3),"AntiKt_Tower_r03");
  towerjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.4),"AntiKt_Tower_r04");
  towerjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.5),"AntiKt_Tower_r05");
  towerjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.6),"AntiKt_Tower_r06");
  towerjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.7),"AntiKt_Tower_r07");
  towerjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.8),"AntiKt_Tower_r08");
  towerjetreco->set_algo_node("ANTIKT");
  towerjetreco->set_input_node("TOWER");
  towerjetreco->Verbosity(verbosity);
  se->registerSubsystem(towerjetreco);

  // topo cluster jets
  JetReco *topoclusterjetreco = new JetReco("TOPOCLUSTERJETRECO");
  topoclusterjetreco->add_input(new ClusterJetInput(Jet::HCAL_TOPO_CLUSTER));
  topoclusterjetreco->add_input(new ClusterJetInput(Jet::ECAL_TOPO_CLUSTER));
  topoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.2),"AntiKt_TopoCluster_r02");
  topoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.3),"AntiKt_TopoCluster_r03");
  topoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.4),"AntiKt_TopoCluster_r04");
  topoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.5),"AntiKt_TopoCluster_r05");
  topoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.6),"AntiKt_TopoCluster_r06");
  topoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.7),"AntiKt_TopoCluster_r07");
  topoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.8),"AntiKt_TopoCluster_r08");
  topoclusterjetreco->set_algo_node("ANTIKT");
  topoclusterjetreco->set_input_node("CLUSTER");
  topoclusterjetreco->Verbosity(verbosity);
  se->registerSubsystem(topoclusterjetreco);

  // template cluster jets
  JetReco *templateclusterjetreco = new JetReco("TEMPLATECLUSTERJETRECO");
  templateclusterjetreco->add_input(new ClusterJetInput(Jet::CEMC_CLUSTER));
  templateclusterjetreco->add_input(new ClusterJetInput(Jet::HCALIN_CLUSTER));
  templateclusterjetreco->add_input(new ClusterJetInput(Jet::HCALOUT_CLUSTER));
  templateclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.2),"AntiKt_TemplateCluster_r02");
  templateclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.3),"AntiKt_TemplateCluster_r03");
  templateclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.4),"AntiKt_TemplateCluster_r04");
  templateclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.5),"AntiKt_TemplateCluster_r05");
  templateclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.6),"AntiKt_TemplateCluster_r06");
  templateclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.7),"AntiKt_TemplateCluster_r07");
  templateclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.8),"AntiKt_TemplateCluster_r08");
  templateclusterjetreco->set_algo_node("ANTIKT");
  templateclusterjetreco->set_input_node("CLUSTER");
  templateclusterjetreco->Verbosity(verbosity);
  se->registerSubsystem(templateclusterjetreco);

  // Hcal topo + CEMC cluster jets
  JetReco *hcaltopocemcclusterjetreco = new JetReco("HCALTOPOCEMCCLUSTERJETRECO");
  hcaltopocemcclusterjetreco->add_input(new ClusterJetInput(Jet::CEMC_CLUSTER));
  hcaltopocemcclusterjetreco->add_input(new ClusterJetInput(Jet::HCAL_TOPO_CLUSTER));
  //hcaltopocemcclusterjetreco->add_input(new ClusterJetInput(Jet::ECAL_TOPO_CLUSTER));
  //hcaltopocemcclusterjetreco->add_input(new ClusterJetInput(Jet::HCALIN_CLUSTER));
  //hcaltopocemcclusterjetreco->add_input(new ClusterJetInput(Jet::HCALOUT_CLUSTER));
  hcaltopocemcclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.2),"AntiKt_HcaltopoCemcCluster_r02");
  hcaltopocemcclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.3),"AntiKt_HcaltopoCemcCluster_r03");
  hcaltopocemcclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.4),"AntiKt_HcaltopoCemcCluster_r04");
  hcaltopocemcclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.5),"AntiKt_HcaltopoCemcCluster_r05");
  hcaltopocemcclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.6),"AntiKt_HcaltopoCemcCluster_r06");
  hcaltopocemcclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.7),"AntiKt_HcaltopoCemcCluster_r07");
  hcaltopocemcclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.8),"AntiKt_HcaltopoCemcCluster_r08");
  hcaltopocemcclusterjetreco->set_algo_node("ANTIKT");
  hcaltopocemcclusterjetreco->set_input_node("CLUSTER");
  hcaltopocemcclusterjetreco->Verbosity(verbosity);
  se->registerSubsystem(hcaltopocemcclusterjetreco);

  // Hcal in/out + EMCAL topo cluster jets
  JetReco *hcalinoutecaltopoclusterjetreco = new JetReco("HCALINOUTECALTOPOCLUSTERJETRECO");
  hcalinoutecaltopoclusterjetreco->add_input(new ClusterJetInput(Jet::ECAL_TOPO_CLUSTER));
  hcalinoutecaltopoclusterjetreco->add_input(new ClusterJetInput(Jet::HCALIN_CLUSTER));
  hcalinoutecaltopoclusterjetreco->add_input(new ClusterJetInput(Jet::HCALOUT_CLUSTER));
  hcalinoutecaltopoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.2),"AntiKt_HcalinoutEcaltopoCluster_r02");
  hcalinoutecaltopoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.3),"AntiKt_HcalinoutEcaltopoCluster_r03");
  hcalinoutecaltopoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.4),"AntiKt_HcalinoutEcaltopoCluster_r04");
  hcalinoutecaltopoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.5),"AntiKt_HcalinoutEcaltopoCluster_r05");
  hcalinoutecaltopoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.6),"AntiKt_HcalinoutEcaltopoCluster_r06");
  hcalinoutecaltopoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.7),"AntiKt_HcalinoutEcaltopoCluster_r07");
  hcalinoutecaltopoclusterjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.8),"AntiKt_HcalinoutEcaltopoCluster_r08");
  hcalinoutecaltopoclusterjetreco->set_algo_node("ANTIKT");
  hcalinoutecaltopoclusterjetreco->set_input_node("CLUSTER");
  hcalinoutecaltopoclusterjetreco->Verbosity(verbosity);
  se->registerSubsystem(hcalinoutecaltopoclusterjetreco);
  
  // track jets
  JetReco *trackjetreco = new JetReco("TRACKJETRECO");
  trackjetreco->add_input(new TrackJetInput(Jet::TRACK,TRACKING::TrackNodeName));
  trackjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.2),"AntiKt_Track_r02");
  trackjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.3),"AntiKt_Track_r03");
  trackjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.4),"AntiKt_Track_r04");
  trackjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.5),"AntiKt_Track_r05");
  trackjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.6),"AntiKt_Track_r06");
  trackjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.7),"AntiKt_Track_r07");
  trackjetreco->add_algo(new FastJetAlgo(Jet::ANTIKT,0.8),"AntiKt_Track_r08");
  trackjetreco->set_algo_node("ANTIKT");
  trackjetreco->set_input_node("TRACK");
  trackjetreco->Verbosity(verbosity);
  se->registerSubsystem(trackjetreco); 

  return; 
}

void Jet_Eval(const std::string &outfilename = "g4jets_eval.root")
{
int verbosity = std::max(Enable::VERBOSITY, Enable::JETS_VERBOSITY);

  Fun4AllServer *se = Fun4AllServer::instance();

  JetEvaluator* eval = new JetEvaluator("JETEVALUATOR",
   					"AntiKt_Tower_r03",
   					"AntiKt_Truth_r03",
   					outfilename);
  eval->Verbosity(verbosity);
  se->registerSubsystem(eval);
  
  return;
}
