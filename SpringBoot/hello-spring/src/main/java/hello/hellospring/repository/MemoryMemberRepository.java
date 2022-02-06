package hello.hellospring.repository;

import hello.hellospring.domain.Member;
import org.springframework.stereotype.Repository;

import java.util.*;

//@Repository
public class MemoryMemberRepository implements MemberRepository{

    private static Map<Long,Member> store = new HashMap<>(); //Map<key,value>
    private static long sequence = 0L; //0L : 자바의 정수 자료형의 기본은 int, long으로 자료형을 변환해주기 위해 0L을 붙여줌
    
    @Override
    public Member save(Member member) {
        member.setId(++sequence);
        store.put(member.getId(),member); //put(): Map에 저장하는 함수
        return member;
    }

    @Override
    public Optional<Member> findById(Long Id) { //찾은 Id의 Member로 반환
        return Optional.ofNullable(store.get(Id));
    }

    @Override
    public Optional<Member> findByName(String name) {
        return store.values().stream() //stream() : 저장 요소를 하나씩 참조해서 람다식으로 처리할 수 있도록 해주는 반복자
                .filter(member -> member.getName().equals(name)) //filter(): stream 내 요소에 대해 필터링하는 작업
                .findAny(); //findAny() : 조건에 일치하는 요소 1개 리턴
    }

    @Override
    public List<Member> findAll() {
        return new ArrayList<>(store.values()); //ArrayList<>() : 크기가 정해져 있지 않은 배열, List 인터페이스를 상속받은 클래스
    }

    public void clearStore(){
        store.clear();
    }
}
