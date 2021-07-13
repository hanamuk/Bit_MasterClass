using Oracle.ManagedDataAccess.Client;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
  
    class DataBase
    {
        static string connect_info = "Data Source=(DESCRIPTION=(ADDRESS_LIST=(ADDRESS=(PROTOCOL=TCP)(HOST={0})(PORT=1521)))(CONNECT_DATA=(SERVER=DEDICATED)(SERVICE_NAME={JSDB})));User ID={id};Password={pass};Connection Timeout=30;";




        public OracleConnection dbConn()
        {
            OracleConnection conn = new OracleConnection(connect_info);
            conn.Open();

            return conn;
        }

        public void release(OracleConnection conn)
        {
            if (conn != null)
            {
                try
                {
                    conn.Close();
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                }
            }
        }
        public void creatTable()
        {
            OracleConnection conn = dbConn();

            //DataSet ds = new DataSet();
            string SQL = "CREATE TABLE phonebook ( " +
                "no number NOT NULL, " +
                "name varchar2(12) NOT NULL, " +
                "pnumber varchar2(30) NOT NULL)"; //쿼리의 끝에 ;을 넣지 마세요.

            OracleCommand oc1 = new OracleCommand(SQL, conn);
            oc1.ExecuteNonQuery();

            release(conn);
        }
        public ArrayList sawon()
        {
            ArrayList al = new ArrayList();

            OracleConnection conn = dbConn();

            //DataSet ds = new DataSet();
            string SQL = "SELECT sabun,saname, deptno, sajob from sawon ";

            OracleCommand oc2 = new OracleCommand(SQL, conn);
            OracleDataReader reader = oc2.ExecuteReader();

            while (reader.Read())
            {
                Sawon b = new Sawon();
                b.sabun = reader.GetInt32(0);
                b.saname = reader.GetString(1);
                b.deptno = reader.GetInt32(2);
                b.sajob = reader.GetString(3);
                b.sapay = reader.GetInt32(4);
                b.sahire = reader.GetString(5);
                b.sase = reader.GetString(6);
                b.samgr = reader.GetInt32(6);
                b.comm = reader.GetInt32(6);
                al.Add(b);
            }

            release(conn);

            return al;
        }
    }
}
