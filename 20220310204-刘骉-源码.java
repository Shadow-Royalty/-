import java.io.*;
import java.util.*;

class Person implements Serializable 
{
	 protected String id;  //Ա�����
	    protected String name;  //����
	    protected String gender;  //�Ա�
	    protected int age;  //����
	    
	    Person(String id, String name, String gender, int age) {
	        this.id = id;
	        this.name = name;
	        this.gender = gender;
	        this.age = age;
	    }
	    
	    void display()
	    {
	    	
	    }

}

class Teacher extends Person implements Serializable {
	protected String department;  //����ϵ��
	protected String major;  //רҵ
	protected String title;  //ְ��

    Teacher(String id, String name, String gender, int age, String department, String major, String title) {
        super(id, name, gender, age);//���ø��๹�췽�������
        //����Ϊ�˲���ǰ������ݣ� �����þͲ��ܽ���Ϣ���뵽������ʹ��
        this.department = department;
        this.major = major;
        this.title = title;
    }
    
    void display() {  //��ʾ��ʦ��Ϣ
        System.out.println("��ţ�" + id + "��������" + name + "���Ա�" + gender + "�����䣺" + age
            + "������ϵ����" + department + "��רҵ��" + major + "��ְ�ƣ�" + title);
    }

}

class LaboratoryStaff extends Person implements Serializable {
	protected String laboratory;  //����ʵ����
	protected String duty;  //ְ��

    LaboratoryStaff(String id, String name, String gender, int age, String laboratory, String duty) {
        super(id, name, gender, age);
        this.laboratory = laboratory;
        this.duty = duty;
    }
    
    void display() {  //��ʾʵ��Ա��Ϣ
        System.out.println("��ţ�" + id + "��������" + name + "���Ա�" + gender + "�����䣺" + age
            + "������ʵ���ң�" + laboratory + "��ְ��" + duty);
    }

    }

class Administrator extends Person implements Serializable  {
	protected String politicalStatus;  //������ò
	protected String title;  //ְ��

    Administrator(String id, String name, String gender, int age, String politicalStatus, String title) {
        super(id, name, gender, age);
        this.politicalStatus = politicalStatus;
        this.title = title;
    }
    
    void display() {  //��ʾ������Ա��Ϣ
        System.out.println("��ţ�" + id + "��������" + name + "���Ա�" + gender + "�����䣺" + age
            + "��������ò��" + politicalStatus + "��ְ�ƣ�" + title);
    }

    }

class TeacherAdministrator extends Teacher implements Serializable 
{
	protected String politicalStatus;  //������ò

    TeacherAdministrator(String id, String name, String gender, int age, String department, String major, String title,String politicalStatus) {
        super(id, name, gender, age,department,major,title);//���ø��๹�췽�������
        //����Ϊ�˲���ǰ������ݣ� �����þͲ��ܽ���Ϣ���뵽������ʹ��
        this.politicalStatus=politicalStatus;
      
    }
    
	void display() {  //��ʾ��ʦ��������Ա��Ϣ
	    System.out.println("��ţ�" + id + "��������" + name + "���Ա�" + gender + "�����䣺" + age
	        + "������ϵ����" + department + "��רҵ��" + major + "��ְ�ƣ�" + title + "��������ò��" + politicalStatus);
	}

}


class PersonManager//��Ϣ����ϵͳ
{
	private static Scanner input=new Scanner(System.in);
	private Person persons[]=new Person[1000];//�˵ĸ���
	private int count =0;//��¼�˵�������Ҳ�������ݸ���
	
	
	//��equals������ж��Ƿ�����ظ�id
	private boolean idExists(String id)//�ж�id�Ƿ���ڵķ���
	{
		for(int i=0;i<count;i++)
			if(persons[i].id.equals(id))
				return true;
		return false;
	}
	
	private int findIndexById(String id)//����id�ķ���
	{
		for(int i=0;i<count;i++)
			if(persons[i].id.equals(id))
				return i;
		
		return -1;
	}
	
	//��������ʱ��ֻ��Ҫ�����ݲ��뵽���м��ɣ�
	void addPerson()//��ӹ���
	{
		   System.out.println("��ѡ��Ҫ��ӵ���Ա���1.��ʦ 2.ʵ��Ա 3.������Ա 4.��ʦ��������Ա");
		   int choice=input.nextInt();
		   String id, name, gender;
	        int age;
	        System.out.println("������Ա�����:");
	        id=input.next();
	        System.out.println("������������");
	        name = input.next();
	        System.out.println("�������Ա�");
	        gender = input.next();
	        System.out.println("���������䣺");
	        age = input.nextInt();
		   
	        if(idExists(id))
	        {
	        	 System.out.println("����Ѵ��ڣ��޷���ӣ�");
	        	 return;//����ȥ����ѡ��
	        }
		   
		   
		   switch(choice)
		   {
		   case 1:
			   String department, major, title;
               System.out.println("����������ϵ����");
               department = input.next();
               System.out.println("������רҵ��");
               major = input.next();
               System.out.println("������ְ�ƣ�");
               title = input.next();
               persons[count++]=new Teacher(id, name, gender, age, department, major, title);
            		//ʹ��persons���ٿռ䴢�棬����teacher����
            		   //����ʹ��teacher��Ϊ�࣬��Ϊteacherû�п��ٿռ�
               break;//��Ҫ©дbreak!
               //��Ȼ��ֱ�ӱ�������һ��case
		   case 2:
               String laboratory, duty;
               System.out.println("����������ʵ���ң�");
               laboratory = input.next();
               System.out.println("������ְ��");
               duty = input.next();
               persons[count++] = new LaboratoryStaff(id, name, gender, age, laboratory, duty);
               break;
           case 3:
               String politicalStatus, adminTitle;
               System.out.println("������������ò��");
               politicalStatus = input.next();
               System.out.println("������ְ�ƣ�");
               adminTitle = input.next();
               persons[count++] = new Administrator(id, name, gender, age, politicalStatus, adminTitle);
               break;	   
           case 4:
        	   //��ʦ��������Ա�������ԣ����Ҫʹ�ü̳�������ʹ���µ��࣡
        	   //���ڽ�ʦ�Ļ����϶��������ò
        	   //String department, major, title,politicalStatus;
        	   //switch�������ı������ǹ���ģ�ֻҪ�������涼�ǹ��õģ�
        	   System.out.println("����������ϵ����");
               department = input.next();
               System.out.println("������רҵ��");
               major = input.next();
               System.out.println("������ְ�ƣ�");
               title = input.next();
               System.out.println("������������ò��");
               politicalStatus = input.next();
        	   persons[count++] = new TeacherAdministrator(id, name, gender, age,department,major,title,politicalStatus);
        	   break;	
        	   
        	   
            		   
               
		   }
		   System.out.println("������ӳɹ���");//�ɶ���
	}
	
	void searchPerson()//��ѯ����
	{
		System.out.println("��ѡ���ѯ��ʽ��1.��� 2.����");
		String keyword;
		int choice=input.nextInt();
		
		boolean found =false;
		 System.out.println("�������ѯ�ؼ��֣�");
	        keyword = input.next();
		for(int i=0;i<count;i++)
			//��Ϊ�п���������ͬ������ͬ���ͬ�������Բ����������ֱ��break
		{
			if(choice==1&&persons[i].id.equals(keyword))
			{
					found=true;
			      persons[i].display();
			      //��Ϊ��������person�����ж�����ϵͳ�У�����Ҫ
			      //��display����д��person������
			}
			
			else if(choice==2&&persons[i].name.equals(keyword))
			{
				found=true;
				 persons[i].display();
			}
				
			
		}
		if(!found)
		{
			System.out.println("δ�ҵ���Ӧ�ļ�¼��");
		}
		
	}
	
	void displayAll()//չʾ����
	{
		if(count==0)
		{
		    System.out.println("��¼Ϊ�գ�");
			return;
		}
		
		System.out.println("ϵͳ�й���" + count + "����¼���������£�");
		for(int i=0;i<count;i++)
		{
			persons[i].display();
		}
	}
	
	void editPerson()//�༭����
	{
		System.out.println("������Ҫ�޸ĵ���Ա��Ϣ��ţ�");
		String id=input.next();
		
	int	index=findIndexById(id);//Ѱ���±�
		if(index==-1)
		{
			System.out.println("δ�ҵ���Ӧ�ļ�¼��");
			return;
		}
		
		  persons[index].display();
  	    System.out.println("��ѡ��Ҫ�޸ĵ����ݣ�1.���� 2.�Ա� 3.����");
//���ı�ţ���Ϊ�����Ψһ�ģ�
		
  	  if (persons[index] instanceof Teacher) {
	        System.out.println("4.����ϵ�� 5.רҵ 6.ְ��");
	    } else if (persons[index] instanceof LaboratoryStaff) {
	        System.out.println("4.����ʵ���� 5.ְ��");
	    } else if (persons[index] instanceof Administrator) {
	        System.out.println("4.������ò 5.ְ��");
	    } else if (persons[index] instanceof TeacherAdministrator) {
	        System.out.println("4.����ϵ�� 5.רҵ 6.ְ�� 7.������ò");
	    }


  	  int choice = input.nextInt();
	    switch (choice) {
	        case 1:
	            System.out.println("�������µ�������");
	            persons[index].name = input.next();
	            break;//�ǵ�дbreak;���һֱ������ȥ
	        case 2:
	            System.out.println("�������µ��Ա�");
	            persons[index].gender = input.next();
	            break;
	        case 3:
	            System.out.println("�������µ����䣺");
	            persons[index].age = input.nextInt();
	            break;
		//ְҵ��case
	            //�ж����ĸ���,��Ϊְҵ�ĳ�Ա���ǲ�ͬ��
	        case 4:
	            if (persons[index] instanceof Teacher || persons[index] instanceof TeacherAdministrator) {
	                System.out.println("�������µ�����ϵ����");
	                ((Teacher) persons[index]).department = input.next();
	            } else if (persons[index] instanceof LaboratoryStaff) {
	                System.out.println("�������µ�����ʵ���ң�");
	                ((LaboratoryStaff) persons[index]).laboratory = input.next();
	            } else if (persons[index] instanceof Administrator) {
	                System.out.println("�������µ�������ò��");
	                ((Administrator) persons[index]).politicalStatus = input.next();
	            }
	            break;
	        case 5:
	            if (persons[index] instanceof Teacher || persons[index] instanceof TeacherAdministrator) {
	                System.out.println("�������µ�רҵ��");
	                ((Teacher) persons[index]).major = input.next();
	            } else if (persons[index] instanceof LaboratoryStaff) {
	                System.out.println("�������µ�ְ��");
	                ((LaboratoryStaff) persons[index]).duty = input.next();
	            } else if (persons[index] instanceof Administrator) {
	                System.out.println("�������µ�ְ�ƣ�");
	                ((Administrator) persons[index]).title = input.next();
	            } else if (persons[index] instanceof TeacherAdministrator) {
	                System.out.println("�������µ�רҵ��");
	                ((TeacherAdministrator) persons[index]).major = input.next();
	            }
	            break;
	        case 6:
	            if (persons[index] instanceof Teacher || persons[index] instanceof TeacherAdministrator) {
	                System.out.println("�������µ�ְ�ƣ�");
	                ((Teacher) persons[index]).title = input.next();
	            } else if (persons[index] instanceof Administrator) {
	                System.out.println("�������µ�ְ�ƣ�");
	                ((Administrator) persons[index]).title = input.next();
	            } else if (persons[index] instanceof TeacherAdministrator) {
	                System.out.println("�������µ�ְ�ƣ�");
	                ((TeacherAdministrator) persons[index]).title = input.next();
	            }
	            break;
	        case 7:
	            if (persons[index] instanceof TeacherAdministrator) {
	                System.out.println("�������µ�������ò��");
	                ((TeacherAdministrator) persons[index]).politicalStatus = input.next();
	            }
	            break;
	        default:
	            System.out.println("��������ȷ��ѡ��");
	            break;
	    }
		
	    System.out.println("�޸ĳɹ���");
			
		}
		
		
		
		
			
	
	
	void deletePerson()//ɾ������
	{
		  System.out.println("������Ҫɾ������Ա��Ϣ��ţ�");
		  String id=input.next();
		  
		  int index=findIndexById(id);
		  if(index==-1)
		  {
			  System.out.println("δ�ҵ���Ӧ�ļ�¼��");
			  return;
		  }
		  
		  for(int i=index;i<count-1;i++)
		  {
			  persons[i]=persons[i+1];
		  }
		  
		  count--;
		  System.out.println("ɾ���ɹ���");
	}
	
	void statistic()//ͳ������
	{
		  int teacherCount = 0;           // ��ʦ����
  	    int labStaffCount = 0;          // ʵ������Ա����
  	    int adminCount = 0;             // ����Ա����
  	    int teacherAdminCount = 0;      // ��ʦ��������Ա����
  	    int maleCount = 0;              // ��������
  	    int femaleCount = 0;            // Ů������

  	    for (int i = 0; i < count; i++) {
  	        if (persons[i] instanceof Teacher) {
  	            teacherCount++;
  	        } else if (persons[i] instanceof LaboratoryStaff) {
  	            labStaffCount++;
  	        } else if (persons[i] instanceof Administrator) {
  	            adminCount++;
  	        } else if (persons[i] instanceof TeacherAdministrator) {
  	            teacherAdminCount++;
  	        }

  	        if (persons[i].gender.equals("��")) {
  	            maleCount++;
  	        } else if (persons[i].gender.equals("Ů")) {
  	            femaleCount++;
  	        }
  	    }

  	    System.out.println("��ʦ������" + teacherCount);
  	    System.out.println("ʵ������Ա������" + labStaffCount);
  	    System.out.println("����Ա������" + adminCount);
  	    System.out.println("��ʦ��������Ա������" + teacherAdminCount);
  	    System.out.println("����������" + maleCount);
  	    System.out.println("Ů��������" + femaleCount);
	}
  

    	//����Ա��Ϣд���ļ�
    	void writeToFile() {
    	    try {
    	    	File file=new File("person.dat");
    	    	if(!file.exists())
    	    	{
    	    		file.createNewFile();
    	    	}
    	    	
    	        FileOutputStream fos = new FileOutputStream(file);
    	        ObjectOutputStream oos = new ObjectOutputStream(fos);
    	        oos.writeObject(persons);
    	        oos.writeInt(count);
    	        oos.close();
    	        fos.close();
    	        System.out.println("�������ݳɹ�!");
    	    } catch (IOException e) {
    	        e.printStackTrace();
    	    }
    	}
    	
     	//���ļ��ж�ȡ��Ա��Ϣ
        void readFromFile() {
        	    try {
        	        File file = new File("person.dat");
        	        //���ļ��ڱ�����������ռ�
        	        if (file.exists()) {
        	            FileInputStream fis = new FileInputStream(file);
        	            ObjectInputStream ois = new ObjectInputStream(fis);
        	            persons = (Person[]) ois.readObject();
        	            //д(Person[]) ��Ϊ�˰�ȫת����Person[]������
        	            count = ois.readInt();
        	            ois.close();
        	            fis.close();
        	            
        	            System.out.println("��ȡ���ݳɹ�!");
        	        }
        	    } catch (FileNotFoundException e) {
        	        System.out.println("�ļ������ڣ�");
        	    } catch (IOException e) {
        	        e.printStackTrace();
        	    } catch (ClassNotFoundException e) {
        	        e.printStackTrace();
        	    }
        	}
	
}
public class Test {
	public static void main(String args[])
	{
    	PersonManager pm=new PersonManager();
    	Scanner input=new Scanner(System.in);
    	
    	while(true)//һֱѭ������Ϊ�˳���һֱ���У��Ϳ���һֱʹ�ù��ܣ�����Ҫ��ѭ����
    		//��Ȼ��������һ�����ڣ�ֱ���˳�����
    	{
    		System.out.println("==============================");
            System.out.println("       ��Ա��Ϣ����ϵͳ");
            System.out.println("==============================");
            System.out.println("1. �����Ա��Ϣ");
            System.out.println("2. ��ѯ��Ա��Ϣ");
            System.out.println("3. ��ʾȫ����Ա��Ϣ");
            System.out.println("4. �༭��Ա��Ϣ");
            System.out.println("5. ɾ����Ա��Ϣ");
            System.out.println("6. ͳ����Ա��Ϣ");
            System.out.println("7. ������Ա��Ϣ���ļ�");
            System.out.println("8. ���ļ���ȡ��Ա��Ϣ");
            System.out.println("0. �˳�����");
             System.out.print("����������ѡ�� ");
           
    		int choice=input.nextInt();
    		
    		switch(choice)
    		{
    		case 1:
    			   pm.addPerson();
	                break;
    		 case 2:
	                pm.searchPerson();
	                break;
    		 case 3:
	                pm.displayAll();
	                break;
	            case 4:
	                pm.editPerson();
	                break;
	            case 5:
	                pm.deletePerson();
	                break;     
	            case 6:
	            	pm.statistic();
	            	break;
	            case 7:
	            	pm.writeToFile();
	            	break;
	            case 8:
	            	pm.readFromFile();
	            	break;
	            case 0: 
	            	System.out.println("�ǳ��ɹ���");
	            	System.exit(0);
	            	 break;
	               default:
	                System.out.println("��������ȷ��ѡ��");
	                break;
	         	
	         
    			
    		}
    	}
    	
    	
	}
}
