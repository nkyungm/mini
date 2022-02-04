package hello.hellospring.repository;

import hello.hellospring.domain.Member;

import java.util.List;
import java.util.Optional;

public interface MemberRepository {
    Member save(Member member); //회원이 저장소에 저장
    Optional<Member> findById(Long Id); //반환 시, Id가 NULL 값이면 Optional형태로 감싸서 반환
    Optional<Member> findByName(String name); //반환 시, name이 NULL 값이면 Optional형태로 감싸서 반환
    List<Member> findAll(); //모든 회원들을 리스트 형식으로 반환
}
