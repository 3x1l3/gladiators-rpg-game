//Job cc file
//author : jordan peoples
//date : november 23 2010
//defines what the job class can handle and do

#include "Job.h"

         Job::Job()
         {
                   jobName = "IF YOU SEE THIS, THERE IS AN ERROR. SHOULD BE WIZARD,ARCHER OR PALADIN";
         }              
         
         Job::~Job()
         {
         }
         
         std::string Job::GetJobName()
         {
                return jobName;
         }
         void Job::SetJobName(std::string name)
         {
             jobName = name;
         }
         
         int* Job::GetStatArray()
         {
             return *statArray;
         }
