create sequence sabun_no_seq
   increment by 2
   start with 201
   maxvalue 299;

create or replace procedure p_sawon_ex_in
   (v_name sawon.saname%type,
   v_sapay sawon.sapay%type,
   v_sajob sawon.sajob%type,
   v_sasex sawon.sasex%type,
   v_samgr sawon.samgr%type,
   v_dname dept.dname%type
   )
is
begin
   insert into sawon(sabun, saname ,deptno , sajob ,sapay , sahire , sasex , samgr , comm) 
                 values(sabun_no_seq.nextval, v_name , 
                (select deptno from dept where dname = v_dname),
                  v_sajob , v_sapay , sysdate ,v_sasex, v_samgr ,
                  case v_dname when '康诀何' then v_sapay*0.1
                when '包府何' then v_sapay*0.1
                else 0 end);
   
end;
