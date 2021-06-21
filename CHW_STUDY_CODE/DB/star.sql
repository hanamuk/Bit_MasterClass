
create or replace function f_star
	(v_pay number)
	return varchar2
is

begin
	return lpad( '*' , v_pay/100, '*');

end;
/