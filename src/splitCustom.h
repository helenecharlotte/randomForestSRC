#ifndef RFSRCSPLITCUST_H
#define RFSRCSPLITCUST_H

/* 
   vvvvvvvv External Constants Below -- Do Not Change vvvvvvvv
*/

#define LEFT      0x01
#define RIGHT     0x00

#define CLAS_FAM     0
#define REGR_FAM     1
#define SURV_FAM     2
#define CRSK_FAM     3

/* 
   ^^^^^^^^ External Constants Above -- Do Not Change ^^^^^^^^
*/


/* 
   vvvvvvvv Do Not Touch These Delarations Below vvvvvvvv
*/

void registerCustomFunctions();

extern void registerThis (double (*func) (unsigned int    n,
                                          char           *membership,
                                          double         *time,
                                          double         *event,

                                          unsigned int    eventTypeSize,
                                          unsigned int    eventTimeSize,
                                          double         *eventTime,

                                          double         *response,
                                          double          mean,
                                          double          variance,
                                          unsigned int    maxLevel),

                          unsigned int family,
                          unsigned int slot);


/* 
   ^^^^^^^^ Do Not Touch These Delarations Above ^^^^^^^^
*/




/*
   Declare your custom funtions below:
*/

double getCustomSplitStatisticMultivariateRegression (unsigned int  n,
                                                      char         *membership,
                                                      double       *time,
                                                      double       *event,

                                                      unsigned int  eventTypeSize,
                                                      unsigned int  eventTimeSize,
                                                      double       *eventTime,

                                                      double       *response,
                                                      double        mean,
                                                      double        variance,
                                                      unsigned int  maxLevel);

double getCustomSplitStatisticMultivariateRegressionGamma (unsigned int  n,
                                                      char         *membership,
                                                      double       *time,
                                                      double       *event,
                                                      
                                                      unsigned int  eventTypeSize,
                                                      unsigned int  eventTimeSize,
                                                      double       *eventTime,
                                                      
                                                      double       *response,
                                                      double        mean,
                                                      double        variance,
                                                      unsigned int  maxLevel);


double getCustomSplitStatisticMultivariateClassification (unsigned int  n,
                                                          char         *membership,
                                                          double       *time,
                                                          double       *event,

                                                          unsigned int  eventTypeSize,
                                                          unsigned int  eventTimeSize,
                                                          double       *eventTime,

                                                          double       *response,
                                                          double        mean,
                                                          double        variance,
                                                          unsigned int  maxLevel);

double getCustomSplitStatisticSurvival (unsigned int  n,
                                        char         *membership,
                                        double       *time,
                                        double       *event,

                                        unsigned int  eventTypeSize,
                                        unsigned int  eventTimeSize,
                                        double       *eventTime,

                                        double       *response,
                                        double        mean,
                                        double        variance,
                                        unsigned int  maxLevel);

double getCustomSplitStatisticSurvival2 (unsigned int  n,
                                        char         *membership,
                                        double       *time,
                                        double       *event,
                                        
                                        unsigned int  eventTypeSize,
                                        unsigned int  eventTimeSize,
                                        double       *eventTime,
                                        
                                        double       *response,
                                        double        mean,
                                        double        variance,
                                        unsigned int  maxLevel);


double getCustomSplitStatisticSurvival3 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);


double getCustomSplitStatisticSurvival4 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);


double getCustomSplitStatisticSurvival5 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticSurvival6 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticSurvival7 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticSurvival8 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticSurvival9 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticSurvival10(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticSurvival11(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticSurvival12(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticSurvival13(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticSurvival14(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticSurvival15(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);


double getCustomSplitStatisticCompetingRisk (unsigned int  n,
                                             char         *membership,
                                             double       *time,
                                             double       *event,

                                             unsigned int  eventTypeSize,
                                             unsigned int  eventTimeSize,
                                             double       *eventTime,

                                             double       *response,
                                             double        mean,
                                             double        variance,
                                             unsigned int  maxLevel);

double getCustomSplitStatisticCompetingRisk2 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);


double getCustomSplitStatisticCompetingRisk3 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);


double getCustomSplitStatisticCompetingRisk4 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);


double getCustomSplitStatisticCompetingRisk5 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticCompetingRisk6 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticCompetingRisk7 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticCompetingRisk8 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticCompetingRisk9 (unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticCompetingRisk10(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticCompetingRisk11(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticCompetingRisk12(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticCompetingRisk13(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticCompetingRisk14(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);

double getCustomSplitStatisticCompetingRisk15(unsigned int  n,
                                         char         *membership,
                                         double       *time,
                                         double       *event,
                                         
                                         unsigned int  eventTypeSize,
                                         unsigned int  eventTimeSize,
                                         double       *eventTime,
                                         
                                         double       *response,
                                         double        mean,
                                         double        variance,
                                         unsigned int  maxLevel);


unsigned int *alloc_uivector(unsigned int nh);
void          dealloc_uivector(unsigned int *v, unsigned int nh);

double       *alloc_dvector(double *v, unsigned int nh);
void          dealloc_dvector(double *v, unsigned int nh);

unsigned int **alloc_uimatrix(unsigned int n2h, unsigned int nh);
void          dealloc_uimatrix(unsigned int **v, unsigned int n2h, unsigned int nh);

/* RF_CRAN_BEG */
#endif
/* RF_CRAN_END */
