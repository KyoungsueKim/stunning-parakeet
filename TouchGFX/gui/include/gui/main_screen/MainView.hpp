#ifndef MAIN_VIEW_HPP
#define MAIN_VIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include <gui/containers/CustomListElement.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    /**
     * Handler of list element clicks.
     */
    void listElementClicked(CustomListElement& element);

protected:
    static const int numberOfListElements = 10;

    CustomListElement listElements[numberOfListElements];

    // Callback that is assigned to each list element
    Callback<MainView, CustomListElement&> listElementClickedCallback;
};

#endif // MAIN_VIEW_HPP
