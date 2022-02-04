package hello.hellospring.repository;

import hello.hellospring.domain.Member;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Test;

import java.util.List;
import java.util.Optional;

import static org.assertj.core.api.Assertions.*;

class MemoryMemberRepositoryTest {

    MemoryMemberRepository repository=new MemoryMemberRepository();

    @AfterEach //각 test가 끝날 때마다 실행되는 함수
    public void afterEach() {
        repository.clearStore(); //저장소 삭제
    }

    @Test
    public void save(){
        Member member = new Member();
        member.setName("spring");
        //Member member1 = new Member();
        //member1.setName("Nam");
        repository.save(member);
        //repository.save(member1);

        Member result = repository.findById(member.getId()).get(); //ctrl+Alt+v : 변수 추출
        //System.out.println("result = "+(result==member));
        //Assertions.assertEquals(member,result); //위의 코드와 같은 동작(출력은 X), member와 result가 동일한 지 확인
        assertThat(member).isEqualTo(result); //위의 코드와 같은 동작(출력은 X), member와 result가 동일한 지 확인
    }

    @Test
    public void findByName(){

        Member member1 = new Member();
        member1.setName("spring1");
        repository.save(member1);

        Member member2 = new Member();
        member2.setName("spring2");
        repository.save(member2);

        Member result = repository.findByName("spring1").get(); //.get() : Optional<Member>의 Member를 꺼내오는 함수

        assertThat(result).isEqualTo(member1); //member와 result가 동일한 지 확인
    }

    @Test
    public void findAll(){
        Member member1=new Member();
        member1.setName("spring1");
        repository.save(member1);

        Member member2=new Member();
        member2.setName("spring2");
        repository.save(member2);
        
        List<Member> result=repository.findAll();

        assertThat(result.size()).isEqualTo(2);
    }
}
