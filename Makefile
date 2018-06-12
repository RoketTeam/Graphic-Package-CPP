CXX = x86_64-w64-mingw32-g++
CPPFLAGS = -std=c++1z -static -g
OBJS += Button/Button.o
# OBJS += CheckList/CheckList.o
# OBJS += ComboBox/ComboBox.o
OBJS += IBorder/IBorder.o
OBJS += IBorder/IBorderStyle.o
OBJS += IBorder/OneLine.o
OBJS += IBorder/DoubleLine.o
OBJS += Control/Control.o
OBJS += EventEngine/EventEngine.o
OBJS += Graphics/Graphics.o
# OBJS += IComposite/IComposite.o
OBJS += IListener/IListener.o
OBJS += IObserver/IObservable.o
OBJS += Label/Label.o
OBJS += FinalProject/Source.o
# OBJS += ListItem/ListItem.o
# OBJS += MessageBox/MessageBox.o
OBJS += NumericBox/NumericBox.o
# OBJS += Panel/Panel.o
# OBJS += RadioBox/RadioBox.o
# OBJS += TextBox/TextBox.o


%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all:$(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe

clean:
	rm -f $(OBJS)
	rm -f *.exe



