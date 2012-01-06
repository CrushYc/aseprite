/* ASE - Allegro Sprite Editor
 * Copyright (C) 2001-2012  David Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef TOOLS_TOOL_BOX_H_INCLUDED
#define TOOLS_TOOL_BOX_H_INCLUDED

#include <string>
#include <list>
#include <map>

#include "tools/tool.h"

class TiXmlElement;

namespace tools {

namespace WellKnownTools {
  extern const char* RectangularMarquee;
};

typedef std::list<Tool*> ToolList;
typedef ToolList::iterator ToolIterator;
typedef ToolList::const_iterator ToolConstIterator;

typedef std::list<ToolGroup*> ToolGroupList;

// Loads and maintains the group of tools specified in the gui.xml file
class ToolBox
{
public:
  ToolBox();
  ~ToolBox();

  ToolGroupList::iterator begin_group() { return m_groups.begin(); }
  ToolGroupList::iterator end_group() { return m_groups.end(); }

  ToolIterator begin() { return m_tools.begin(); }
  ToolIterator end() { return m_tools.end(); }
  ToolConstIterator begin() const { return m_tools.begin(); }
  ToolConstIterator end() const { return m_tools.end(); }

  Tool* getToolById(const std::string& id);
  int getGroupsCount() const { return m_groups.size(); }

private:
  void loadTools();
  void loadToolProperties(TiXmlElement* xmlTool, Tool* tool, int button, const std::string& suffix);

  std::map<std::string, Ink*> m_inks;
  std::map<std::string, Controller*> m_controllers;
  std::map<std::string, PointShape*> m_pointshapers;
  std::map<std::string, Intertwine*> m_intertwiners;

  ToolGroupList m_groups;
  ToolList m_tools;
};

} // namespace tools

#endif  // TOOLS_TOOL_BOX_H_INCLUDED
