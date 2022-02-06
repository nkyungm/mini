package hello.hellospring.service;

import hello.hellospring.domain.Member;
import hello.hellospring.repository.MemberRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

//@Service
public class MemberService {

    private final MemberRepository memberRepository;

    //@Autowired service -> repository
    public MemberService(MemberRepository memberRepository) {
        this.memberRepository = memberRepository; //외부에서 MemberRepository를 넣어서 사용하도록 변경
    }

    /**
     * 회원 가입
     */

    public Long join(Member member){
        //같은 이름이 있는 중복 회원X
        validateDuplicateMember(member); //중복 회원 검증 (method 형태로 변경)
        memberRepository.save(member);
        return member.getId();
    }

    private void validateDuplicateMember(Member member) {
        memberRepository.findByName(member.getName())
                .ifPresent(m -> {  //ifPresent() : 값의 존재 유무 판단
            throw new IllegalStateException("이미 존재하는 회원입니다.");
            // throw new +(발생시킬 예외); : 강제로 예외를 발생시킴
        });
    }

    /**
     * 전체 회원 조회
     */
    public List<Member> findMembers(){
        return memberRepository.findAll();
    }

    public  Optional<Member> findOne(Long memberId){
        return memberRepository.findById((memberId));
    }

}
