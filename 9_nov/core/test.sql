PGDMP         9    	        
    w            test    11.5 (Debian 11.5-3.pgdg100+1)    11.5 (Debian 11.5-3.pgdg100+1) (    �           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                       false            �           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                       false            �           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                       false            �           1262    24939    test    DATABASE     j   CREATE DATABASE test WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'en_IN' LC_CTYPE = 'en_IN';
    DROP DATABASE test;
             postgres    false            �            1255    25206    select_account()    FUNCTION     y  CREATE FUNCTION public.select_account() RETURNS TABLE(account_id bigint, account_type_id integer, account_name character varying, enabled boolean, account_creation_date timestamp without time zone, balance money, remarks text, currency_id character varying, email_id character varying)
    LANGUAGE plpgsql
    AS $$
BEGIN
    return query SELECT * FROM user_account;
END; $$;
 '   DROP FUNCTION public.select_account();
       public       postgres    false            �            1255    25205    select_profile()    FUNCTION     �  CREATE FUNCTION public.select_profile() RETURNS TABLE(profile_id bigint, firstname character varying, lastname character varying, gender character varying, passport_number character varying, other_id character varying, other_id_type character varying, ssn character varying, date_of_birth date, address1 character varying, address2 character varying, city character varying, state character varying, country character varying, nationality character varying, zipcode character varying, phone_number character varying, agree_for_news_letter boolean, email_id character varying, last_update_time timestamp without time zone)
    LANGUAGE plpgsql
    AS $$
BEGIN
    return query SELECT * FROM user_profile;
END; $$;
 '   DROP FUNCTION public.select_profile();
       public       postgres    false            �            1255    25204    select_user()    FUNCTION     R  CREATE FUNCTION public.select_user() RETURNS TABLE(user_id bigint, username character varying, password character varying, transaction_password character varying, user_enabled boolean, created_time timestamp without time zone, user_type_id integer)
    LANGUAGE plpgsql
    AS $$
BEGIN
    return query SELECT * FROM user_login;
END; $$;
 $   DROP FUNCTION public.select_user();
       public       postgres    false            �            1259    25089    user_account    TABLE     �  CREATE TABLE public.user_account (
    account_id bigint NOT NULL,
    account_type_id integer NOT NULL,
    account_name character varying(256) NOT NULL,
    enabled boolean NOT NULL,
    account_creation_date timestamp without time zone NOT NULL,
    balance money NOT NULL,
    remarks text,
    currency_id character varying(10) NOT NULL,
    email_id character varying(256) NOT NULL
);
     DROP TABLE public.user_account;
       public         postgres    false            �            1259    25087    user_account_account_id_seq    SEQUENCE     �   CREATE SEQUENCE public.user_account_account_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 2   DROP SEQUENCE public.user_account_account_id_seq;
       public       postgres    false    200            �           0    0    user_account_account_id_seq    SEQUENCE OWNED BY     [   ALTER SEQUENCE public.user_account_account_id_seq OWNED BY public.user_account.account_id;
            public       postgres    false    199            �            1259    25122    user_account_profile_map    TABLE     s   CREATE TABLE public.user_account_profile_map (
    account_id integer NOT NULL,
    profile_id integer NOT NULL
);
 ,   DROP TABLE public.user_account_profile_map;
       public         postgres    false            �            1259    25073 
   user_login    TABLE     U  CREATE TABLE public.user_login (
    user_id bigint NOT NULL,
    username character varying(100) NOT NULL,
    password character varying(2048) NOT NULL,
    transaction_password character varying(2048) NOT NULL,
    user_enabled boolean NOT NULL,
    created_time timestamp without time zone NOT NULL,
    user_type_id integer NOT NULL
);
    DROP TABLE public.user_login;
       public         postgres    false            �            1259    25109    user_login_account_map    TABLE     n   CREATE TABLE public.user_login_account_map (
    user_id integer NOT NULL,
    account_id integer NOT NULL
);
 *   DROP TABLE public.user_login_account_map;
       public         postgres    false            �            1259    25071    user_login_user_id_seq    SEQUENCE        CREATE SEQUENCE public.user_login_user_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 -   DROP SEQUENCE public.user_login_user_id_seq;
       public       postgres    false    198            �           0    0    user_login_user_id_seq    SEQUENCE OWNED BY     Q   ALTER SEQUENCE public.user_login_user_id_seq OWNED BY public.user_login.user_id;
            public       postgres    false    197            �            1259    25100    user_profile    TABLE     �  CREATE TABLE public.user_profile (
    profile_id bigint NOT NULL,
    firstname character varying(75) NOT NULL,
    lastname character varying(75) NOT NULL,
    gender character varying(30) NOT NULL,
    passport_number character varying(2048) NOT NULL,
    other_id character varying(2048),
    other_id_type character varying(256),
    ssn character varying(2048) NOT NULL,
    date_of_birth date NOT NULL,
    address1 character varying(256) NOT NULL,
    address2 character varying(256),
    city character varying(100) NOT NULL,
    state character varying(100) NOT NULL,
    country character varying(100) NOT NULL,
    nationality character varying(100) NOT NULL,
    zipcode character varying(30) NOT NULL,
    phone_number character varying(30) NOT NULL,
    agree_for_news_letter boolean NOT NULL,
    email_id character varying(256) NOT NULL,
    last_update_time timestamp without time zone NOT NULL
);
     DROP TABLE public.user_profile;
       public         postgres    false            �            1259    25098    user_profile_profile_id_seq    SEQUENCE     �   CREATE SEQUENCE public.user_profile_profile_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 2   DROP SEQUENCE public.user_profile_profile_id_seq;
       public       postgres    false    202            �           0    0    user_profile_profile_id_seq    SEQUENCE OWNED BY     [   ALTER SEQUENCE public.user_profile_profile_id_seq OWNED BY public.user_profile.profile_id;
            public       postgres    false    201            �            1259    25066 	   user_type    TABLE     t   CREATE TABLE public.user_type (
    user_type_id integer NOT NULL,
    user_type character varying(256) NOT NULL
);
    DROP TABLE public.user_type;
       public         postgres    false            �
           2604    25092    user_account account_id    DEFAULT     �   ALTER TABLE ONLY public.user_account ALTER COLUMN account_id SET DEFAULT nextval('public.user_account_account_id_seq'::regclass);
 F   ALTER TABLE public.user_account ALTER COLUMN account_id DROP DEFAULT;
       public       postgres    false    199    200    200            �
           2604    25076    user_login user_id    DEFAULT     x   ALTER TABLE ONLY public.user_login ALTER COLUMN user_id SET DEFAULT nextval('public.user_login_user_id_seq'::regclass);
 A   ALTER TABLE public.user_login ALTER COLUMN user_id DROP DEFAULT;
       public       postgres    false    197    198    198            �
           2604    25103    user_profile profile_id    DEFAULT     �   ALTER TABLE ONLY public.user_profile ALTER COLUMN profile_id SET DEFAULT nextval('public.user_profile_profile_id_seq'::regclass);
 F   ALTER TABLE public.user_profile ALTER COLUMN profile_id DROP DEFAULT;
       public       postgres    false    201    202    202            �          0    25089    user_account 
   TABLE DATA               �   COPY public.user_account (account_id, account_type_id, account_name, enabled, account_creation_date, balance, remarks, currency_id, email_id) FROM stdin;
    public       postgres    false    200   9       �          0    25122    user_account_profile_map 
   TABLE DATA               J   COPY public.user_account_profile_map (account_id, profile_id) FROM stdin;
    public       postgres    false    204   :9       �          0    25073 
   user_login 
   TABLE DATA               �   COPY public.user_login (user_id, username, password, transaction_password, user_enabled, created_time, user_type_id) FROM stdin;
    public       postgres    false    198   W9       �          0    25109    user_login_account_map 
   TABLE DATA               E   COPY public.user_login_account_map (user_id, account_id) FROM stdin;
    public       postgres    false    203   j:       �          0    25100    user_profile 
   TABLE DATA                 COPY public.user_profile (profile_id, firstname, lastname, gender, passport_number, other_id, other_id_type, ssn, date_of_birth, address1, address2, city, state, country, nationality, zipcode, phone_number, agree_for_news_letter, email_id, last_update_time) FROM stdin;
    public       postgres    false    202   �:       ~          0    25066 	   user_type 
   TABLE DATA               <   COPY public.user_type (user_type_id, user_type) FROM stdin;
    public       postgres    false    196   �:       �           0    0    user_account_account_id_seq    SEQUENCE SET     J   SELECT pg_catalog.setval('public.user_account_account_id_seq', 1, false);
            public       postgres    false    199            �           0    0    user_login_user_id_seq    SEQUENCE SET     D   SELECT pg_catalog.setval('public.user_login_user_id_seq', 4, true);
            public       postgres    false    197            �           0    0    user_profile_profile_id_seq    SEQUENCE SET     J   SELECT pg_catalog.setval('public.user_profile_profile_id_seq', 1, false);
            public       postgres    false    201            �
           2606    25097    user_account user_account_pkey 
   CONSTRAINT     d   ALTER TABLE ONLY public.user_account
    ADD CONSTRAINT user_account_pkey PRIMARY KEY (account_id);
 H   ALTER TABLE ONLY public.user_account DROP CONSTRAINT user_account_pkey;
       public         postgres    false    200            �
           2606    25081    user_login user_login_pkey 
   CONSTRAINT     ]   ALTER TABLE ONLY public.user_login
    ADD CONSTRAINT user_login_pkey PRIMARY KEY (user_id);
 D   ALTER TABLE ONLY public.user_login DROP CONSTRAINT user_login_pkey;
       public         postgres    false    198            �
           2606    25108    user_profile user_profile_pkey 
   CONSTRAINT     d   ALTER TABLE ONLY public.user_profile
    ADD CONSTRAINT user_profile_pkey PRIMARY KEY (profile_id);
 H   ALTER TABLE ONLY public.user_profile DROP CONSTRAINT user_profile_pkey;
       public         postgres    false    202            �
           2606    25070    user_type user_type_pkey 
   CONSTRAINT     `   ALTER TABLE ONLY public.user_type
    ADD CONSTRAINT user_type_pkey PRIMARY KEY (user_type_id);
 B   ALTER TABLE ONLY public.user_type DROP CONSTRAINT user_type_pkey;
       public         postgres    false    196                       2606    25125 A   user_account_profile_map user_account_profile_map_account_id_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.user_account_profile_map
    ADD CONSTRAINT user_account_profile_map_account_id_fkey FOREIGN KEY (account_id) REFERENCES public.user_account(account_id) ON DELETE RESTRICT;
 k   ALTER TABLE ONLY public.user_account_profile_map DROP CONSTRAINT user_account_profile_map_account_id_fkey;
       public       postgres    false    200    204    2813                       2606    25130 A   user_account_profile_map user_account_profile_map_profile_id_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.user_account_profile_map
    ADD CONSTRAINT user_account_profile_map_profile_id_fkey FOREIGN KEY (profile_id) REFERENCES public.user_profile(profile_id) ON DELETE RESTRICT;
 k   ALTER TABLE ONLY public.user_account_profile_map DROP CONSTRAINT user_account_profile_map_profile_id_fkey;
       public       postgres    false    2815    204    202                       2606    25112 =   user_login_account_map user_login_account_map_account_id_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.user_login_account_map
    ADD CONSTRAINT user_login_account_map_account_id_fkey FOREIGN KEY (account_id) REFERENCES public.user_account(account_id) ON DELETE RESTRICT;
 g   ALTER TABLE ONLY public.user_login_account_map DROP CONSTRAINT user_login_account_map_account_id_fkey;
       public       postgres    false    203    200    2813                       2606    25117 :   user_login_account_map user_login_account_map_user_id_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.user_login_account_map
    ADD CONSTRAINT user_login_account_map_user_id_fkey FOREIGN KEY (user_id) REFERENCES public.user_login(user_id) ON DELETE RESTRICT;
 d   ALTER TABLE ONLY public.user_login_account_map DROP CONSTRAINT user_login_account_map_user_id_fkey;
       public       postgres    false    198    203    2811                        2606    25082 '   user_login user_login_user_type_id_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.user_login
    ADD CONSTRAINT user_login_user_type_id_fkey FOREIGN KEY (user_type_id) REFERENCES public.user_type(user_type_id) ON DELETE RESTRICT;
 Q   ALTER TABLE ONLY public.user_login DROP CONSTRAINT user_login_user_type_id_fkey;
       public       postgres    false    198    196    2809            �      x������ � �      �      x������ � �      �     x�}Q�JA<�~������1�x/�!�Y̮�=��vm�$^z�k��{z8���~<�� �͌i������j��R&\ɖ��1to���U�,�X=���)E��zvD22�ķ�~�8L[&x"\��$s���\@�@S�g��]}B8w����'��<(�*	%H2��Q��T���X�@F��[�/O�]��{w#-+v�$���FC�8���y��u|x�5��b__Co��:�-���ȗS�������úA�UU� e�y�      �      x������ � �      �      x������ � �      ~      x�3�LL�������� $�     