#pragma once

#include "openlr/openlr_match_quality/openlr_assessment_tool/traffic_mode.hpp"

#include "base/string_utils.hpp"

#include <string>

#include <QMainWindow>

class Framework;
class MapWidget;
class TrafficMode;

namespace df
{
class DrapeApi;
}

class QDockWidget;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(Framework & framework);

private:
  void CreateTrafficPanel(std::string const & dataFilePath);
  void DestroyTrafficPanel();

  void OnOpenTrafficSample();
  void OnCloseTrafficSample();
  void OnSaveTrafficSample();
  void OnPathEditingStop();

  Framework & m_framework;

  TrafficMode * m_trafficMode = nullptr;
  QDockWidget * m_docWidget = nullptr;

  QAction * m_saveTrafficSampleAction = nullptr;
  QAction * m_closeTrafficSampleAction = nullptr;
  QAction * m_startEditingAction = nullptr;
  QAction * m_commitPathAction  = nullptr;
  QAction * m_cancelPathAction = nullptr;

  MapWidget * m_mapWidget = nullptr;
};
