create or replace procedure p_state
      (v_hire varchar2,
      v_res out varchar2)
is
      hire varchar2(10);
      ave number(10);
      cnt number(10);

begin
      select to_char(sahire, 'yyyy'), avg(sapay), count(*) into hire, ave, cnt from sawon
      where to_char(sahire, 'yyyy') = v_hire
   group by to_char(sahire, 'yyyy');
   
      v_res := '�Ի�⵵ : ' || hire || '��ձ޿� : ' || ave || '�ο���' || cnt;
   
end;
/