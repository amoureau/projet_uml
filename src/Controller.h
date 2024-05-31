#if ! defined ( CONTROLLER_H )
#define CONTROLLER_H


#include "ComputationAgent.h"
#include "User.h"
#include "Admin.h"
#include "Results.h"




class Controller
{
    public:
        int mainController(void);

        Controller();
        virtual ~Controller ( );	

    private:
        ComputationAgent *calculateur;
        User *user;
        Results *result;
};

#endif