using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
   
    public partial class Form1 : Form
    {
        ArrayList data = new ArrayList();
        public Form1()
        {
            InitializeComponent();
            
            Sawon first = new Sawon(10,"실험체",23,"감자몬",7333,"어제","남자",32,2333);
            data.Add(first);
        }

        private void Login_Click(object sender, EventArgs e)
        {
            /*
            DataBase db = new DataBase();
            ArrayList al = new ArrayList();
            al = db.sawon();

            IEnumerator item = al.GetEnumerator();
            while (item.MoveNext())
            {
                Sawon b = (Sawon)(item.Current);
                MessageBox.Show(b.sabun + " ");
                MessageBox.Show(b.saname + " ");
                MessageBox.Show(b.deptno + "\n");
                MessageBox.Show(b.sajob + "\n");
                MessageBox.Show(b.sapay + "\n");
                MessageBox.Show(b.sahire + "\n");
                MessageBox.Show(b.sase + "\n");
                MessageBox.Show(b.samgr + "\n");
                MessageBox.Show(b.comm + "\n");
            }
            */

            //로그인 기능.
            foreach (Sawon item in data)
            {
                //로그인 성공
                if (TBid.Text.Equals(item.saname) && TBpass.Text.Equals(item.sabun.ToString()))
                {
               
                    MainPage mPage = new MainPage();
                    this.Visible = false;
                    mPage.ShowDialog();
                   
                }    

            }
            



        }
    }
}
