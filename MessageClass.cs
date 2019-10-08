using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace csharp1
{
    class MessageClass
    {
        public string greeting
        {
            get;
            set;
        }

        public string CreateGreeting(string greetee)
        {
            return greeting + " " + greetee;
        }
    }
}