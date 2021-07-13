using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class Sawon
    {
        public Sawon() { }
        public Sawon(int bun, string name, int dept, string job , int pay, string hire, string sase, int samgr, int comm) 
        {
            this.sabun = bun;
            this.saname = name;
            this.deptno = dept;
            this.sajob = job;
            this.sapay = pay;
            this.sahire = hire;
            this.sase = sase;
            this.samgr = samgr;
            this.comm = comm;

        }
        public int sabun { get; set; }
        public string saname { get; set; }
        public int deptno { get; set; }
        public string sajob { get; set; }
        public int sapay { get; set; }
        public string sahire { get; set; }
        public string sase { get; set; }
        public int samgr { get; set; }
        public int comm { get; set; }

    }
}
