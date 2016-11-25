#include "endturnwindow.h"
#include <QPushButton>
#include <QDebug>

#include "mainwindow.h"

endturnwindow::endturnwindow(QWidget *parent,int height, int width) : QWidget(parent) {
    //Set the size of the window
    int win_wth=width;//256;
    int win_hth=height;//128;
    setFixedSize(win_wth, win_hth);

    // CONDITIONAL - if too many cards, bring up the card removal window




    // =========================================================== //
    // Create and position the CARD buttons
    // =========================================================== //
    // NOTE: should they be buttons? If so, would need to dynamically
    // determine the potential actions, so dynamically assign slots!
    int but_x=10;  // first button x-coord
    int but_y=20;  //button y-coord
    int but_gap=5; //gap between buttons
    int but_wth=(win_wth-2.0*but_x-6.0*but_gap)/7.0;
    int but_hth=but_wth*1.56; // playing card width/height ratio is 1:1.56
    int but_x_offset=but_wth+but_gap; //button x-offset
    int but_y_offset=(win_hth-but_y)/2.0; //button y-offset (2nd row)

    // PLACEHOLDER "CARDS"

    // First card
    card_button1 = new QPushButton("CARD 1", this);
    card_button1->setGeometry(but_x, but_y, but_wth, but_hth);
    card_button1->setToolTip("Opens a menu for special actions");
    card_button1->setCheckable(true);



    // Seventh card
    card_button7 = new QPushButton("CARD 7", this);
    card_button7->setGeometry(but_x+6*but_x_offset, but_y, but_wth, but_hth);
    card_button7->setToolTip("Opens a menu for special actions");
    card_button7->setCheckable(true);



    // Eighth card (new row)
    QPushButton *card_button8 = new QPushButton("CARD 8", this);
    card_button8->setGeometry(but_x, but_y+but_y_offset, but_wth, but_hth);
    card_button8->setToolTip("Opens a menu for special actions");
    card_button8->setCheckable(true);


    // CONFIRM END OF TURN
    endturn_button = new QPushButton("END TURN", this);
    endturn_button->setGeometry(but_x+3*but_x_offset, but_y+but_y_offset, but_wth*2, but_hth);
    endturn_button->setToolTip("Ends the turn");

    connect(endturn_button, SIGNAL (clicked()), this, SLOT (endturnClicked()));


}

void endturnwindow::endturnClicked() {
    // Get the parent (to get the world)
    mainWindow* parent = qobject_cast<mainWindow*>(this->parent());

    qDebug() << "Turn ended. \n";

    // Close end-turn window
    this->close();

    // Draw cards and infect
    int player = parent->world->players_turn;
    parent->world->draw_player_deck(*parent->world->heroes[player]);
    /*
     * HAND LIMIT CHECK - should be done, but then would need to be
     * careful that we don't exit this function and end-up drawing
     * extra cards -- would need to exit to allow for the selection --
     * otherwise the turn will change and the hand window is for the
     * wrong player!
    if(parent->world->heroes[player]->hand.size() > 7) {
        emit handLimit();
        return;
    }
    */
    parent->world->draw_infection_deck();

    // Change turn
    parent->world->next_player_turn();

    // Update the disease cubes
    parent->updateDiseases();

    // Update the progress bars
    qDebug() << "Progress bars to be updated - STUB \n";

    // Update the action LCD
    parent->action_lcd->check_actions();

    // Update the hand window
    player = parent->world->players_turn;
    parent->getHandWindow()->update_window(parent->world->heroes[player]);

}
