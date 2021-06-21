-- 행단위로 같은 작업을 하는 테이블 커서를 정의하여 일괄처리 가능!! (목적)// 행단위 실행(for 문이나 fetch 중하나 선택)

-- 모든사원의 이름과 급여를 출력하는 커서를 정의

declare 
	cursor mycur is select saname, sapay from sawon;
	
	
begin

	for i in mycur loop 
		dbms_output.put_line('이름: '|| i.saname || '급여 : '|| i.sapay );
	end loop;


end;
/

-----------------------------------------------------
--원래 정석

declare 
	cursor mycur is select saname, sapay from sawon;
	v_name sawon.saname%type;
	v_pay	sawon.sapay%type;
begin 

	if mycur%isopen then
		close mycur;
	end if;
	open mycyr;
	loop
		fetch mycur into v_name, v_pay;
		exit when(mycur%notfound);
		반복할 명령 등...
	end loop;
	close mycur;
end;
/
-------------------------------------------------------