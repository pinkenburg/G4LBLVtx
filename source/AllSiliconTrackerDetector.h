// Tell emacs that this is a C++ source
//  -*- C++ -*-.
#ifndef ALLSILICONTRACKERDETECTOR_H
#define ALLSILICONTRACKERDETECTOR_H

#include <g4main/PHG4Detector.h>

#include <map>
#include <set>
#include <string>  // for string

class AllSiliconTrackerDisplayAction;
class G4LogicalVolume;
class G4VPhysicalVolume;
class PHCompositeNode;
class PHG4Subsystem;
class PHParameters;

class AllSiliconTrackerDetector : public PHG4Detector
{
 public:
  //! constructor
  AllSiliconTrackerDetector(PHG4Subsystem *subsys, PHCompositeNode *Node, PHParameters *parameters, const std::string &dnam);

  //! destructor
  virtual ~AllSiliconTrackerDetector() {}

  //! construct
  void ConstructMe(G4LogicalVolume *world) override;

  void Print(const std::string &what = "ALL") const override;

  //!@name volume accessors
  //@{
  int IsInDetector(G4VPhysicalVolume *) const;
  //@}

  void SuperDetector(const std::string &name) { m_SuperDetector = name; }
  const std::string SuperDetector() const { return m_SuperDetector; }

 private:
  enum
  {
    insertassemblies = 1,
    insertlogicalvolumes = 2
  };
  void InsertVolumes(G4VPhysicalVolume *physvol, const int flag);
  AllSiliconTrackerDisplayAction *m_DisplayAction;
  PHParameters *m_Params;

  std::string m_GDMPath;

  std::string m_SuperDetector;
  int m_Active;
  int m_AbsorberActive;

  // active volumes
  std::map<G4VPhysicalVolume *, int> m_ActivePhysicalVolumesSet;
  std::map<G4VPhysicalVolume *, int> m_PassivePhysicalVolumesSet;
};

#endif  // ALLSILICONTRACKERDETECTOR_H
