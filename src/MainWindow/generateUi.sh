if ! uic mainWindow.ui > UiMainWindow.hpp
then
  echo "Error while creating UiMainWindow.hpp"
else
  echo "UiMainWindow.hpp created"
fi

if ! uic startupDialog.ui > UiStartupDialog.hpp
then
  echo "Error while creating UiStartupDialog.hpp"
else
  echo "UiStartupDialog.hpp created"
fi
