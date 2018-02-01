#include  <stdlib.h>
#include  <math.h>
#include  "splitCustom.h"

/*

  Before coding a custom split rule, you must register it with the
  family specific vector of custom split rules.  This allows the user
  to code from one (1) to sixteen (16) different split rules for each
  family.  In the following function, each sample split rule is
  registered in slot one (1) of the family specific vector of custom
  split rules.

  The specific rule for slot X in the vector, where 1 <= X <= 16, is
  activated by the R-code user parameter:  splitrule = "customX".
  
  Note that splitrule = "custom" is the equivalent of splitrule = "custom1".  

  
 */

void registerCustomFunctions() {

  // Register the custom classification split rule in the first slot.
  registerThis (&getCustomSplitStatisticMultivariateClassification, CLAS_FAM, 1);
  
  // Register the custom regression split rule in the first slot.
  registerThis (&getCustomSplitStatisticMultivariateRegression, REGR_FAM, 1);
  
  // Register the custom regression split rule in the first slot.
  registerThis (&getCustomSplitStatisticMultivariateRegressionGamma, REGR_FAM, 2); 
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival, SURV_FAM, 1);
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival2, SURV_FAM, 2); // early effects, rho=0.25
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival3, SURV_FAM, 3); // early effects, rho=0.5
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival4, SURV_FAM, 4); // early effects, rho=0.75
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival5, SURV_FAM, 5); // early effects, rho=1

  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival6, SURV_FAM, 6); // early effects, rho=1.5
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival7, SURV_FAM, 7); // early effects, rho=2
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival8, SURV_FAM, 8); // early effects, rho=3

  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival9, SURV_FAM, 9); // late effects, rho=0.25
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival10, SURV_FAM, 10); // late effects, rho=0.5
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival11, SURV_FAM, 11); // late effects, rho=0.75
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival12, SURV_FAM, 12); // late effects, rho=1
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival13, SURV_FAM, 13); // late effects, rho=1.5
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival14, SURV_FAM, 14); // late effects, rho=2
  
  // Register the custom survival split rule in the first slot.
  registerThis (&getCustomSplitStatisticSurvival15, SURV_FAM, 15); // late effects, rho=3
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk, CRSK_FAM, 1);

  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk2, CRSK_FAM, 2); // early effects, rho=0.25
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk3, CRSK_FAM, 3); // early effects, rho=0.5
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk4, CRSK_FAM, 4); // early effects, rho=0.75
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk5, CRSK_FAM, 5); // early effects, rho=1
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk6, CRSK_FAM, 6); // early effects, rho=1.5
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk7, CRSK_FAM, 7); // early effects, rho=2
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk8, CRSK_FAM, 8); // early effects, rho=3
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk9, CRSK_FAM, 9); // late effects, rho=0.25
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk10, CRSK_FAM, 10); // early effects, rho=0.5
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk11, CRSK_FAM, 11); // early effects, rho=0.75
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk12, CRSK_FAM, 12); // early effects, rho=1
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk13, CRSK_FAM, 13); // early effects, rho=1.5
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk14, CRSK_FAM, 14); // early effects, rho=2
  
  // Register the custom competing risk split rule in the first slot.
  registerThis (&getCustomSplitStatisticCompetingRisk15, CRSK_FAM, 15); // early effects, rho=3
  
  
  // If you have more than one function of each type, you would
  // uncomment one or more of the following statements and complete
  // the coding for the named functions.  Note that you can call these
  // functions anything you want.  In a multivariate scenario you must
  // be sure that the index of both the classification and regression
  // split rule are identical.  For example, in a multivariate
  // scenario, splitrule = "custom2", will call the classification
  // split rule in the second slot, along with the regression split
  // rule in the second slot if the respones contain factors and reals.

  //  registerThis (&getCustomSplitStatisticMultivariateClassificationTwo, CLAS_FAM, 2);
  //  registerThis (&getCustomSplitStatisticMultivariateRegressionTwo, REGR_FAM, 2);
  //  registerThis (&getCustomSplitStatisticSurvivalTwo, SURV_FAM, 2);
  //  registerThis (&getCustomSplitStatisticCompetingRiskTwo, CRSK_FAM, 2);

}


/*
  Generic Custom Split Rule Harness

  Function Inputs:
  n - number of replicates in the parent node to be split

  membership     - vector of length n representing daughter node
  membership (LEFT or RIGHT) as a result of the
  test split.

  time     - vector of length n of time variable for survival data sets.
  This will be NULL for non-survival data sets.
  event   - vector of length n of event/censoring variable for
  survival data sets.  This will be NULL for non-survival
  data sets.

  response - vector of length n of response variable (y-outcome) in the
  node. In the multivariate case this function will be called 
  once for each response.  The multivariate split statistic 
  is the sum of the individual response statistic.  It is 
  important to normalize the statistic for each response to 
  avoid one response overwhelming another's value.  This will 
  be NULL for survival data sets.

  mean     - convenience value representing the mean of the response vector
  variance - convenience value representing the variance of the response vector

  maxLevel - convenience value representing the maximum level for this factor respone
  in the data set as a whole.  This will be NULL for non-factor respones.


  Function Output:  returns custom split statistic

  Depending on the split statistic, the user may need to allocate and 
  de-allocate arrays of various dimensions.  A typical alloc/de-alloc is
  defined in this file:

  unsigned int *alloc_uivector(...)
  void        dealloc_uivector(...)

  Always remember to deallocate what has been allocated.

  Always remember to declare the function in the corresponding ".h" file.

*/


double getCustomSplitStatisticMultivariateRegression (unsigned int n,
                                                      char        *membership,
                                                      double      *time,
                                                      double      *event,

                                                      unsigned int eventTypeSize,
                                                      unsigned int eventTimeSize,
                                                      double      *eventTime,

                                                      double      *response,
                                                      double       mean,
                                                      double       variance,
                                                      unsigned int maxLevel)
{

  // EXAMPLE:  Multivariate Regression

  // Local variables needed for this example:
  double sumLeft, sumRght;
  double sumLeftSqr, sumRghtSqr;
  double delta;

  // Left and right normalization sizes.
  unsigned int leftSize, rghtSize;

  unsigned int i;

  // Initialization of local variables:
  sumLeft = sumRght = 0.0;
  leftSize = rghtSize = 0;

  delta = 0.0;

  // In general, calculating a split statistic will require iterating
  // over all members in the parent node, and ascertaining daughter
  // membership, and performing a well defined calculation based on
  // membership.  In this example, the sum of the difference from the
  // mean for the y-outcome in each daughter node is calculated.

  for (i = 1; i <= n; i++) {
    // Membership will be either LEFT or RIGHT.  
    if (membership[i] == LEFT) {
      // Add the left member to the sum.
      sumLeft += response[i] - mean;
      leftSize ++;
    }
    else {
      // Add the right member to the sum.
      sumRght += response[i] - mean;
      rghtSize ++;
    }
  }

  // Finally, we calculate the composite mean square error for each daughter.
  sumLeftSqr = pow(sumLeft, 2.0) / ((double) leftSize * variance);
  sumRghtSqr = pow(sumRght, 2.0) / ((double) rghtSize * variance);

  delta = sumLeftSqr + sumRghtSqr;

  return delta;
}

double getCustomSplitStatisticMultivariateRegressionGamma (unsigned int n,
                                                      char        *membership,
                                                      double      *time,
                                                      double      *event,
                                                      
                                                      unsigned int eventTypeSize,
                                                      unsigned int eventTimeSize,
                                                      double      *eventTime,
                                                      
                                                      double      *response,
                                                      double       mean,
                                                      double       variance,
                                                      unsigned int maxLevel)
{
  
  // EXAMPLE:  Multivariate Regression
  
  // Local variables needed for this example:
  double sumLeft, sumRght;
  double sumLeftSqr, sumRghtSqr;
  double delta;
  double leftFrac, rghtFrac;
  
  // Left and right normalization sizes.
  unsigned int leftSize, rghtSize;
  
  unsigned int i;
  
  // Initialization of local variables:
  sumLeft = sumRght = 0.0;
  leftSize = rghtSize = 0;
  leftFrac = rghtFrac = 0.0;
  
  delta = 0.0;
  
  // In general, calculating a split statistic will require iterating
  // over all members in the parent node, and ascertaining daughter
  // membership, and performing a well defined calculation based on
  // membership.  In this example, the sum of the difference from the
  // mean for the y-outcome in each daughter node is calculated.
  
  for (i = 1; i <= n; i++) {
    // Membership will be either LEFT or RIGHT.  
    if (membership[i] == LEFT) {
      // Add the left member to the sum.
      sumLeft += response[i] - mean;
      leftFrac += response[i] / ((double) n);
      leftSize ++;
    }
    else {
      // Add the right member to the sum.
      sumRght += response[i] - mean;
      rghtFrac += response[i] / ((double) n);
      rghtSize ++;
    }
  }
  
  // Finally, we calculate the composite mean square error for each daughter.
  sumLeftSqr = pow(sumLeft, 2.0) / ((double) leftSize * variance);
  sumRghtSqr = pow(sumRght, 2.0) / ((double) rghtSize * variance);
  
  delta = sumLeftSqr + sumRghtSqr;
  
  // leftFrac = leftSize / ((double) n);
  // rghtFrac = rghtSize / ((double) n);
  
  if ((leftFrac == 0.0) || (rghtFrac == 0.0)) {
    return leftFrac; 
  } else {  
    return leftFrac; 
  }
}


double getCustomSplitStatisticMultivariateClassification (unsigned int n,
                                                          char        *membership,
                                                          double      *time,
                                                          double      *event,

                                                          unsigned int eventTypeSize,
                                                          unsigned int eventTimeSize,
                                                          double      *eventTime,
                                                          
                                                          double      *response,
                                                          double       mean,
                                                          double       variance,
                                                          unsigned int maxLevel)
{

  // EXAMPLE:  Multivariate Classification

  // Local variables needed for this example:
  unsigned int   *leftClassProp, *rghtClassProp;
  double sumLeftSqr, sumRghtSqr;
  double delta;

  // Arrays needed for multivariate regression:
  double sumLeft, sumRght;

  // Left and right normalization sizes.
  unsigned int leftSize, rghtSize;

  unsigned int i, p;

  // Initialization of local variables:
  sumLeft = sumRght = 0.0;
  leftSize = rghtSize = 0;

  delta = 0.0;

  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for class counts.
  leftClassProp = alloc_uivector(maxLevel);
  rghtClassProp = alloc_uivector(maxLevel);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//

  // Initialize the class counts.
  for (p = 1; p <= maxLevel; p++) {
    leftClassProp[p] = rghtClassProp[p] = 0;
  }
  
  // In general, calculating a split statistic will require iterating
  // over all members in the parent node, and ascertaining daughter
  // membership, and performing a well defined calculation based on
  // membership.  In this example, the left and right class counts for
  // the y-outcome in each daughter node are calculated.
  for (i = 1; i <= n; i++) {
    // Membership will be either LEFT or RIGHT.  Package specific
    // constants are contained in global.h.
    if (membership[i] == LEFT) {

      // Add the left member to the left class proportion.
      leftClassProp[(unsigned int) response[i]] ++;
      leftSize ++;

    }
    else {

      // Add the right member to the left class proportion.
      rghtClassProp[(unsigned int) response[i]] ++;
      rghtSize ++;

    }
  }

  for (p = 1; p <= maxLevel; p++) {
    sumLeft += pow((double) leftClassProp[p], 2.0);
    sumRght += pow((double) rghtClassProp[p], 2.0);
  }

  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for class counts.
  dealloc_uivector(leftClassProp, maxLevel);
  dealloc_uivector(rghtClassProp, maxLevel);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//

  sumLeftSqr = sumLeft / leftSize;
  sumRghtSqr = sumRght / rghtSize;
  
  
  delta = sumLeftSqr + sumRghtSqr;

  return delta;
}

double getCustomSplitStatisticSurvival (unsigned int n,
                                        char        *membership,
                                        double      *time,
                                        double      *event,

                                        unsigned int eventTypeSize,
                                        unsigned int eventTimeSize,
                                        double      *eventTime,

                                        double      *response,
                                        double       mean,
                                        double       variance,
                                        unsigned int maxLevel)
{

  // EXAMPLE:  Survival (logrank)

  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;

  double delta, deltaNum, deltaDen;
  unsigned int i, k;

  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;

  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);

  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//

  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }

  k = eventTimeSize;
  i = n;

  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {

    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {

      // The member is still at risk!
      nodeParentAtRisk[k] ++;

      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
        
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;

          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }

      // Examine the previous individual.
      i--;
    }
    else {

      // Examine the previous event time.
      k--;
    }
  }

  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }

  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    deltaNum = deltaNum + ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));

    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + (
                             ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
                             (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
                             ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
                             );

    }
  }


  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);

  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }

  return delta; 

}


double getCustomSplitStatisticSurvival2 (unsigned int n,
                                        char        *membership,
                                        double      *time,
                                        double      *event,
                                        
                                        unsigned int eventTypeSize,
                                        unsigned int eventTimeSize,
                                        double      *eventTime,
                                        
                                        double      *response,
                                        double       mean,
                                        double       variance,
                                        unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 0.25;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }

  survweight = 1; 

  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticSurvival3 (unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 0.5;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticSurvival4 (unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 0.75;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticSurvival5 (unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 1.0;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticSurvival6 (unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 1.5;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticSurvival7 (unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 2.0;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticSurvival8 (unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 3.0;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticSurvival9 (unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 0.25;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(1-survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticSurvival10(unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 0.5;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(1-survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}


double getCustomSplitStatisticSurvival11(unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 0.75;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(1-survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}


double getCustomSplitStatisticSurvival12(unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 1.0;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(1-survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}


double getCustomSplitStatisticSurvival13(unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 1.5;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(1-survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}


double getCustomSplitStatisticSurvival14(unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 2;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(1-survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}


double getCustomSplitStatisticSurvival15(unsigned int n,
                                         char        *membership,
                                         double      *time,
                                         double      *event,
                                         
                                         unsigned int eventTypeSize,
                                         unsigned int eventTimeSize,
                                         double      *eventTime,
                                         
                                         double      *response,
                                         double       mean,
                                         double       variance,
                                         unsigned int maxLevel)
{
  
  // EXAMPLE:  Survival (logrank)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  double delta, deltaNum, deltaDen, weight, survweight, rho;
  unsigned int i, k;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 3;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEvent[k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  survweight = 1; 
  
  // Iterate over the distinct event times and acquire the numerator and denominator of the test.
  for (k = 1; k <= eventTimeSize; k++) {
    survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    weight = pow(1-survweight, rho);
    deltaNum = deltaNum + weight * ((double) nodeLeftEvent[k] - ((double) ( nodeLeftAtRisk[k] * nodeParentEvent[k]) / nodeParentAtRisk[k]));
    
    // Log-Rank denominator requires that there be at least two at risk.
    if (nodeParentAtRisk[k] >= 2) {
      deltaDen = deltaDen + pow(weight, 2.0) * (
        ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k]) *
          (1.0 - ((double) nodeLeftAtRisk[k] / nodeParentAtRisk[k])) *
          ((double) (nodeParentAtRisk[k] - nodeParentEvent[k]) / (nodeParentAtRisk[k] - 1)) * nodeParentEvent[k]
      );
      
    }
  }
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}








double getCustomSplitStatisticCompetingRisk (unsigned int n,
                                             char        *membership,
                                             double      *time,
                                             double      *event,

                                             unsigned int eventTypeSize,
                                             unsigned int eventTimeSize,
                                             double      *eventTime,

                                             double      *response,
                                             double       mean,
                                             double       variance,
                                             unsigned int maxLevel)
{

  // EXAMPLE:  Competing Risk (logrankCR)

  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;

  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;

  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen;
  unsigned int i, j, k, r, s;

  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;

  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);

  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//

  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);

  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//

  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;

    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }

  k = eventTimeSize;
  i = n;

  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {

    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {

      // The member is still at risk!
      nodeParentAtRisk[k] ++;

      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
        
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {

          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;

          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }

      // Examine the previous individual.
      i--;
    }
    else {

      // Examine the previous event time.
      k--;
    }

  }

  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }

  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }

  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {

    deltaSubNum = 0;
    for (k = 1; k <= eventTimeSize; k++) {
      deltaSubNum = deltaSubNum + (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
    }
    deltaNum = deltaNum + deltaSubNum;
    
    deltaSubDen = 0;
    for (k = 1; k <= eventTimeSize; k++) {
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
    }
    deltaDen = deltaDen + deltaSubDen;
  }


  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);

  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//

  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);

  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//

  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }

  return delta;

}

double getCustomSplitStatisticCompetingRisk2 (unsigned int n,
                                             char        *membership,
                                             double      *time,
                                             double      *event,
                                             
                                             unsigned int eventTypeSize,
                                             unsigned int eventTimeSize,
                                             double      *eventTime,
                                             
                                             double      *response,
                                             double       mean,
                                             double       variance,
                                             unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
    double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 0.25;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk3 (unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 0.5;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk4 (unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 0.75;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk5 (unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 1.0;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk6 (unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 1.5;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk7 (unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 2;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk8 (unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = 3;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk9 (unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = -0.25;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk10(unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = -0.5;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk11 (unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = -0.75;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk12(unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = -1;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk13 (unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = -1.5;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk14(unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = -2;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));
      
      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}

double getCustomSplitStatisticCompetingRisk15(unsigned int n,
                                              char        *membership,
                                              double      *time,
                                              double      *event,
                                              
                                              unsigned int eventTypeSize,
                                              unsigned int eventTimeSize,
                                              double      *eventTime,
                                              
                                              double      *response,
                                              double       mean,
                                              double       variance,
                                              unsigned int maxLevel)
{
  
  // EXAMPLE:  Competing Risk (logrankCR)
  
  // Local variables needed for this example:
  unsigned int   *nodeLeftEvent,  *nodeParentEvent;
  unsigned int   *nodeLeftAtRisk, *nodeParentAtRisk;
  
  // Local CR variable needed for this example:
  unsigned int   **nodeLeftEventCR,  **nodeParentEventCR;
  unsigned int   **nodeLeftInclusiveAtRisk, **nodeParentInclusiveAtRisk;
  
  double delta, deltaNum, deltaSubNum, deltaDen, deltaSubDen, weight, survweight, probweight, rho;
  unsigned int i, j, k, r, s;
  
  // Initialization of local variables:
  deltaNum = deltaDen = 0.0;
  rho = -3;
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  nodeLeftEvent   = alloc_uivector(eventTimeSize);
  nodeParentEvent = alloc_uivector(eventTimeSize);
  
  // Vector for at risk counts.
  nodeLeftAtRisk    = alloc_uivector(eventTimeSize);
  nodeParentAtRisk  = alloc_uivector(eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  nodeParentEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftEventCR = alloc_uimatrix(eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  nodeParentInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  nodeLeftInclusiveAtRisk = alloc_uimatrix(eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  // Reset the node specific counts needed for the statistic.
  for (k = 1; k <= eventTimeSize; k++) {
    nodeParentEvent[k]  = 0;
    nodeParentAtRisk[k] = 0;
    nodeLeftEvent[k]    = 0;
    nodeLeftAtRisk[k]   = 0;
    
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentEventCR[j][k]         = 0;
      nodeLeftEventCR[j][k]           = 0;
      nodeParentInclusiveAtRisk[j][k] = 0;
      nodeLeftInclusiveAtRisk[j][k]   = 0;
    }
  }
  
  k = eventTimeSize;
  i = n;
  
  // Iterate over all individuals.  Note that they arrive sorted by time
  // in increasing order.  We parse them in decreasing order.
  while ((i > 0) && (k > 0)) {
    
    // Initialize the parent event count.
    if (eventTime[k] <= time[i]) {
      
      // The member is still at risk!
      nodeParentAtRisk[k] ++;
      
      // Membership will be either LEFT or RIGHT.  
      if (membership[i] == LEFT) {
        nodeLeftAtRisk[k] ++;
      }
      
      // Did the member experience an event?
      if (eventTime[k] == time[i]) {
        if (event[i] > 0) {
          
          nodeParentEventCR[(unsigned int) event[i]][k] ++;
          nodeParentEvent[k] ++;
          
          // Membership will be either LEFT or RIGHT.  
          if (membership[i] == LEFT) {
            nodeLeftEventCR[(unsigned int) event[i]][k] ++;
          }
        }
      }
      
      // Examine the previous individual.
      i--;
    }
    else {
      
      // Examine the previous event time.
      k--;
    }
    
  }
  
  // Adjust the at risk counts to achieve the step function.
  for (k = eventTimeSize; k > 1; k--) {
    nodeParentAtRisk[k-1] = nodeParentAtRisk[k] + nodeParentAtRisk[k-1];
    nodeLeftAtRisk[k-1] = nodeLeftAtRisk[k] + nodeLeftAtRisk[k-1];
  }
  
  // Finalize the left and right inclusive at risk counts.
  for (k = 1; k <= eventTimeSize; k++) {
    for (j = 1; j <= eventTypeSize; j++) {
      nodeParentInclusiveAtRisk[j][k] = nodeParentAtRisk[k];
      nodeLeftInclusiveAtRisk[j][k] = nodeLeftAtRisk[k];
      for (s = 1; s < k; s++) {
        for (r = 1; r <= eventTypeSize; r++) {
          if (j != r) {
            nodeParentInclusiveAtRisk[j][k]  += nodeParentEventCR[r][s];
            nodeLeftInclusiveAtRisk[j][k]  += nodeLeftEventCR[r][s];
          }
        }
      }
    }
  }
  
  // Iterate over the event types and distinct event times and acquire the numerator and denominator of the test.
  for (j = 1; j <= 1; j++) {
    
    deltaSubNum = 0;
    survweight = 1; 
    probweight = 0; 
    deltaSubDen = 0;
    
    for (k = 1; k <= eventTimeSize; k++) {
      probweight = probweight + survweight / ((double) nodeParentAtRisk[k]) * nodeParentEventCR[j][k];
      weight = pow(1-probweight, rho); 
      deltaSubNum = deltaSubNum + weight * (nodeLeftEventCR[j][k] - (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])));

      // Log-Rank CR denominator requires that there be at least two at risk.
      if (nodeParentAtRisk[k] >= 2) {
        deltaSubDen = deltaSubDen  + weight * (
          (nodeParentEventCR[j][k] * ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            (1.0 - ((double) nodeLeftInclusiveAtRisk[j][k] / nodeParentInclusiveAtRisk[j][k])) *
            ((double) (nodeParentInclusiveAtRisk[j][k] - nodeParentEventCR[j][k]) / (nodeParentInclusiveAtRisk[j][k] - 1))
        );
      }
      
      survweight = survweight * (1 - nodeParentEvent[k]  / ((double) nodeParentAtRisk[k]));
    }
    deltaNum = deltaNum + deltaSubNum;
    deltaDen = deltaDen + deltaSubDen;
  }
  
  
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Vector for event counts.
  dealloc_uivector(nodeLeftEvent, eventTimeSize);
  dealloc_uivector(nodeParentEvent, eventTimeSize);
  
  // Vector for at risk counts.
  dealloc_uivector(nodeLeftAtRisk, eventTimeSize);
  dealloc_uivector(nodeParentAtRisk, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  // Matrix containing event counts at each event time.
  dealloc_uimatrix(nodeParentEventCR, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftEventCR, eventTypeSize, eventTimeSize);
  
  // Matrix containing event inclusive at risk counts at each event time.
  dealloc_uimatrix(nodeParentInclusiveAtRisk, eventTypeSize, eventTimeSize);
  dealloc_uimatrix(nodeLeftInclusiveAtRisk, eventTypeSize, eventTimeSize);
  //---------- *** WARNING MEMORY MANIPULATION WARNING *** -----------//
  
  deltaNum = fabs(deltaNum);
  deltaDen = sqrt(deltaDen);
  if (deltaDen <= 1.0e-9) {
    if (deltaNum <= 1.0e-9) {
      delta = 0.0;
    }
    else {
      delta = deltaNum / deltaDen;
    }
  }
  else {
    delta = deltaNum / deltaDen;
  }
  
  return delta;
  
}



/*HER*/


/*
  Memory allocation and deallocation.
    [nh] = the length of the array
    
  Note that indexing is one-based:  
    array[1] ... array[nh]

  Multi-dimensional array allocationis 
  accomplished via multiple one-dimensional
  array allocations.
*/

unsigned int *alloc_uivector(unsigned int nh)
{
  return (unsigned int *) malloc((size_t) ((nh+1) * (sizeof(unsigned int))));
}

void dealloc_uivector(unsigned int *v, unsigned int nh)
{
  free((char *) v);
}


double *alloc_dvector(double *v, unsigned int nh)
{
  return (double *) malloc((size_t) ((nh+1) * (sizeof(double))));
}

void dealloc_dvector(double *v, unsigned int nh)
{
  free((char *) v);
}

unsigned int **alloc_uimatrix(unsigned int n2h, unsigned int nh)
{
  unsigned int **v = (unsigned int **) malloc((size_t) ((n2h+1) * (sizeof(unsigned int *))));

  for (unsigned int i = 1; i <= n2h; i++) {
    v[i] = alloc_uivector(nh);
  }
  return v;
}

void dealloc_uimatrix(unsigned int **v, unsigned int n2h, unsigned int nh)
{
  for (unsigned int i = 1; i <= n2h; i++) {
    dealloc_uivector(v[i], nh);
  }
  free((char *) v);
}
