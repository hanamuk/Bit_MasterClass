
create or replace function f_jumin
	(v_jumin varchar2)
	return varchar2
is
	v_result varchar2(10);
begin
	if substr(v_jumin, 8, 1) = '1' or substr(v_jumin, 8, 1) = '3'  then
	v_result := '����';
	else
	v_result:= '����';

	end if;
	return v_result;
end;
/
