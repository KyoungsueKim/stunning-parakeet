#ifndef MAIN_VIEW_HPP
#define MAIN_VIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include <gui/containers/CustomListElement.hpp>

#ifndef SIMULATOR
#include "main.h"
#endif

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
    void updateBusInfo();
    void addBusInfo(const BusInfo& busInfo);
    void updateMainView();

protected:
    static const int maximumListElements = 40;
    int currentElementIndex = 0; // 현재 리스트 엘리먼트 인덱스

    CustomListElement listElements[maximumListElements];

    // Callback that is assigned to each list element
    Callback<MainView, CustomListElement&> listElementClickedCallback;
};

#endif // MAIN_VIEW_HPP