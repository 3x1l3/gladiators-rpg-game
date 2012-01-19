//Job cc file
//author : jordan peoples
//date : november 23 2010
//defines what the job class can handle and do

#include "Job.h"

         Job::Job() throw()
         {
                   jobName = "IF YOU SEE THIS, THERE IS AN ERROR. SHOULD BE WIZARD,ARCHER OR PALADIN";
         }              
         
         Job::~Job() throw()
         {
         }
         
         std::string Job::GetJobName() throw()
         {
                return jobName;
         }
         void Job::SetJobName(const std::string name) throw()
         {
             jobName = name;
         }
         
         int* Job::GetStatArray() throw()
         {
             return *statArray;
         }

