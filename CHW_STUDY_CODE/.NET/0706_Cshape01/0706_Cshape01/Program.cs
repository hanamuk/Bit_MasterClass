using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using System.Collections;

// 옵저버 패턴 ------------------------------------------------------------------------(통지가 발생하면 클래스가 알려줄떄notify) 많이사용)
namespace _0706_Cshape01
{
    //신문사들의 중복코드를 상속시키기위해.
    class C
    {
        protected ArrayList al = new ArrayList();
        public void add(Person user) { al.Add(user); }
        public void remove(int num) { al.RemoveAt(num); }
    }


    // A 클래스는 신문사(경향일보)이다.
    class A : C
    {
        //고객 관리 리스트.
    
        string news;
        public void setNews(string news)
        {
            this.news = news;
            notify();
        }
        public void notify() //공지
        {
            foreach (Person item in al)
            {
                item.update(news);
            }
        }

     
      
    }

    // B 클래스는 신문사(중앙일보)이다.
    class B : C
    {
        //고객 관리 리스트.
        

        int 온도, 습도;
        public void setNews(int 온도, int 습도)
        {
            this.온도 = 온도;
            this.습도 = 습도;

            notify();
        }
        public void notify() //공지
        {
            foreach (Person item in al)
            {
                //item.update(온도, 습도);
            }
        }

    }



    interface Person
    {
        void update(string name);
       
    }

    class User : Person
    {
        public string name;
        public User(string name) { this.name = name; }
        public void update(string news) 
        {
            WriteLine(name + " : " + news +"에 대하여 뉴스를 시청합니다.");
        }
        //secondUser와 중복되지 않는 코드 10000줄 , 같은 인터페이스를 사용하지만 전혀 다른 성격일 수 있다.

    }

    class secondUser: Person
    {
        public string name;
        public secondUser(string name) { this.name = name; }
        public void update(string news)
        {
            for (int i = 0; i < 2; i++)
            {
                WriteLine(name + " : " + news+ i );
            }
           
        }
        //User 중복되지 않는 코드 10000줄
    }


    class Program
    {
        static void Main(string[] args)
        {
            A a = new A();
            a.add(new User("유저1"));
            a.add(new secondUser("세컨유저1"));
            a.setNews("장마");

            B b = new B();
            b.add(new User("유저2"));
            b.add(new secondUser("세컨유저2"));
            b.setNews(20, 30);


        }
    }
}
